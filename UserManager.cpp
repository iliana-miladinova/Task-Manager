#include "UserManager.h"
#include <fstream>

UserManager::UserManager()
{
    loadUsers();
    loadCollaborations();
}

UserManager::UserManager(const UserManager& other)
{
    copyFrom(other);
}

UserManager& UserManager::operator=(const UserManager& other)
{
    if (this!=&other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

UserManager::UserManager(UserManager&& other) noexcept
{
    moveFrom(std::move(other));
}

UserManager& UserManager::operator=(UserManager&& other) noexcept
{
    if (this!=&other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

UserManager::~UserManager() 
{
    if (currentUser)
    {
        saveTasks(currentUser->getUsername());
        saveCollaborations();
        saveDashboard();
    }
    saveUsers();
    free();
}

void UserManager::copyFrom(const UserManager& other)
{
    users = other.users;
    collaborations = other.collaborations;
    currentUser = other.currentUser;

}

void UserManager::moveFrom(UserManager&& other)
{
    users = std::move(other.users);
    collaborations = std::move(other.collaborations);
    currentUser = other.currentUser;
    other.currentUser = nullptr;
}

void UserManager::free()
{
    delete currentUser;
    currentUser = nullptr;
}

void UserManager::registerUser(const MyString& username, const MyString& password) 
{
    if (findUser(username) != nullptr)
    {
        throw std::runtime_error("User with this username already exists");
    }
    users.pushBack(User(username, password));
    saveUsers();
}

void UserManager::loginUser(const MyString& username, const MyString& password) 
{


    User* user = findUser(username);
    if (user && user->checkPassword(password))
    {
        currentUser = user;
        loadTasks(username);
        loadDashboard();
        loadCollaborations();
    }
    else 
    {
        throw std::runtime_error("Invalid username or password!");
    }
}

void UserManager::logoutUser() 
{
    if (currentUser) 
    {
        saveTasks(currentUser->getUsername());
        saveDashboard();
        saveCollaborations();
        currentUser = nullptr;
    }
}

void UserManager::loadUsers() 
{
    std::ifstream ifs(userFile.c_str(), std::ios::binary);
    if (!ifs) return;

    size_t userCount;
    ifs.read((char*)&userCount, sizeof(userCount));
    for (size_t i = 0; i < userCount; i++) 
    {
        User user;
        user.deserializeUser(ifs);
        users.pushBack(user);
    }
    ifs.close();
}

void UserManager::saveUsers() const  
{
    std::ofstream ofs(userFile.c_str(), std::ios::binary);
    size_t userCount = users.getSize();
    ofs.write((const char*)&userCount, sizeof(userCount));
    for (size_t i = 0; i < userCount; i++) 
    {
        users[i].serializeUser(ofs);
    }
    ofs.close();
}

void UserManager::loadTasks(const MyString& username)
{
    std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    if (!ifs) return;

    size_t taskCount;
    ifs.read((char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++)
    {
        MyString user;
        size_t usernameLength;
        ifs.read((char*)&usernameLength, sizeof(usernameLength));
        char* usernameBuffer = new char[usernameLength + 1];
        ifs.read(usernameBuffer, usernameLength);
        usernameBuffer[usernameLength] = '\0';
        user = MyString(usernameBuffer);
        delete[] usernameBuffer;
        if (user == username) 
        {
            currentUser->deserializeTasks(ifs);
        }
        else {
            size_t taskSize;
            ifs.read((char*)&taskSize, sizeof(taskSize));
            ifs.seekg(taskSize, std::ios::cur);
        }
    }
    ifs.close();
 
}

void UserManager::saveTasks(const MyString& username) const
{
    if (!currentUser)
    {
        return;
    }

    std::ofstream ofs(taskFile.c_str(), std::ios::binary | std::ios::trunc);
    size_t taskCount = currentUser->getTasks().getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++)
    {
        char type;
        if (currentUser->getTasks()[i]->getType() == "ProjectTask")
        {
            type = 'P';
        }
        else
        {
            type = 'T';
        }
        ofs.write(&type, sizeof(type));
        currentUser->getTasks()[i]->serialize(ofs);
    }
    currentUser->getDashboard().serialize(ofs);
    ofs.close();

}

User* UserManager::findUser(const MyString& username)
{
    for (size_t i = 0; i < users.getSize(); i++)
    {
        if (users[i].getUsername() == username) 
        {
            return &users[i];
        }
    }
    return nullptr;
}

User* UserManager::getCurrentUser() const 
{
    return currentUser;
}

void UserManager::updateTaskName(int id, const MyString& name)
{
    if (currentUser) 
    {
        currentUser->updateTaskName(id, name);
        saveTasks(currentUser->getUsername());
    
    }
    else 
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::updateTaskDescription(int id, const MyString& description) 
{
    if (currentUser) 
    {
        currentUser->updateTaskDescription(id, description);
        saveTasks(currentUser->getUsername());
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::removeTaskFromDashboard(int id)
{
    if (currentUser) 
    {
        currentUser->removeTaskFromDashboard(id);
        saveTasks(currentUser->getUsername());
        saveDashboard();
      
    }
    else 
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::addTaskToDashboard(int id)
{
    if (currentUser) 
    {
        currentUser->addTaskToDashboard(id);
        saveTasks(currentUser->getUsername());
        saveDashboard();
   
    }
    else 
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::deleteTask(int id) 
{
    if (currentUser) 
    {
        currentUser->deleteTask(id);
        saveTasks(currentUser->getUsername());
       
    }
    else 
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::getTask(const MyString& name) const
{
    if (currentUser)
    {
        currentUser->getTask(name);
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::getTask(int id) const
{
    if (currentUser)
    {
        currentUser->getTask(id);
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::listTasks(const MyString& dueDate) const
{
    if (currentUser)
    {
        currentUser->listTasks(dueDate);
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::listTasks() const
{
    if (currentUser)
    {
        currentUser->listTasks();
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::listCompletedTasks() const
{
    if (currentUser)
    {
        currentUser->listTasks();
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::startTask(int id)
{
    if (currentUser)
    {
        currentUser->startTask(id);
        saveTasks(currentUser->getUsername());
        saveDashboard();
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::addTask(const MyString& name, const MyString& dueDate, const MyString& description)
{
    if (currentUser)
    {
        currentUser->addTask(name, dueDate, description);
        saveTasks(currentUser->getUsername());
    }
    else
    {
        throw std::runtime_error("No user is logged in!");

    }
}

void UserManager::listDashboard() const
{
    if (currentUser) 
    {
        currentUser->getDashboard().showTask();
    }
    else 
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::finishTask(int id) 
{
    if (currentUser) 
    {
        currentUser->finishTask(id);
        saveTasks(currentUser->getUsername());
        saveDashboard();
    }
    else
    {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::loadCollaborations() 
{
    std::ifstream ifs(collabFile.c_str(), std::ios::binary);
    if (!ifs.is_open()) return;

    size_t collabCount;
    ifs.read((char*)&collabCount, sizeof(collabCount));
    for (size_t i = 0; i < collabCount; i++) 
    {
        Collaboration collab;
        collab.deserialize(ifs);
        collaborations.pushBack(collab);
    }
    ifs.close();
}

void UserManager::saveCollaborations() const 
{
    std::ofstream ofs(collabFile.c_str(), std::ios::binary | std::ios::trunc);
    size_t collabCount = collaborations.getSize();
    ofs.write((const char*)&collabCount, sizeof(collabCount));
    for (size_t i = 0; i < collabCount; i++) 
    {
        collaborations[i].serialize(ofs);
    }
    ofs.close();
}

void UserManager::addCollaboration(const MyString& name) 
{
    if (currentUser == nullptr) 
    {
        throw std::runtime_error("No user is logged in!");
    }
    int newId = collaborations.getSize() + 1;
    Collaboration newCollab(newId, name, currentUser->getUsername());
    collaborations.pushBack(newCollab);
    saveCollaborations();
}

void UserManager::deleteCollaboration(const MyString& name)
{
    if (currentUser == nullptr) 
    {
        throw std::runtime_error("No user is logged in!");
    }

    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getName() == name) 
        {
            if (collaborations[i].getCreator() != currentUser->getUsername()) 
            {
                throw std::runtime_error("You need to be the creator in order to delete this collaboration!");
            }
            collaborations.erase(i);
            saveCollaborations();
            return;
        }
    }
    throw std::runtime_error("Collaboration not found!");
}

void UserManager::listCollaborations() const 
{
    if (currentUser == nullptr) 
    {
        throw std::runtime_error("No user is logged in!");
    }

    std::cout << "Collaborations:" << std::endl;
    for (size_t i = 0; i < collaborations.getSize(); i++) 
    {
        const Collaboration& collab = collaborations[i];
        if (collab.getCreator() == currentUser->getUsername() || collab.isParticipant(currentUser->getUsername()))
        {
            collab.showCollaboration();
        }
    }
}

void UserManager::addUserToCollaboration(const MyString& collabName, const MyString& username)
{
    Collaboration* collab = findCollaborationByName(collabName);
    if (collab == nullptr)
    {
        throw std::runtime_error("Collaboration not found!");
    }
    collab->addParticipant(username);
    saveCollaborations();
    
}

void UserManager::assignTaskToCollaboration(const MyString& collabName, const MyString& username, const MyString& taskName, const MyString& dueDate, const MyString& description)
{
    Collaboration* collab = findCollaborationByName(collabName);
    if (collab == nullptr)
    {
        throw std::runtime_error("Collaboration not found!");
    }
    collab->assignTask(username, taskName, dueDate, description);
    saveCollaborations();
   
}

void UserManager::listCollaborationTasks(const MyString& collabName) const 
{
    const Collaboration* collab = findCollaborationByName(collabName);
    if (collab == nullptr)
    {
        throw std::runtime_error("Collaboration not found!");
    }
    collab->listTasks();
}

const Collaboration* UserManager::findCollaborationByName(const MyString& name) const
{
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getName() == name) 
        {
            return &collaborations[i];
        }
    }
    return nullptr;
}

Collaboration* UserManager::findCollaborationByName(const MyString& name) 
{
    for (size_t i = 0; i < collaborations.getSize(); i++) 
    {
        if (collaborations[i].getName() == name)
        {
            return &collaborations[i];
        }
    }
    return nullptr;
}

void UserManager::saveDashboard() const
{
    if (!currentUser)
    {
        return;
    }

    std::ofstream ofs(dashboardFile.c_str(), std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Could not open file for saving dashboard.");
        return;
    }

    size_t userCount = users.getSize();
    ofs.write((const char*)&userCount, sizeof(userCount));

    for (size_t i = 0; i < userCount; i++) 
    {
        const User& user = users[i];
        size_t usernameLen = user.getUsername().getSize();
        ofs.write((const char*)&usernameLen, sizeof(usernameLen));
        ofs.write(user.getUsername().c_str(), usernameLen);
        user.getDashboard().serialize(ofs);
    }

    ofs.close();
    if (!ofs)
    {
       throw std::runtime_error("Could not write to dashboard file.");
    }
}

void UserManager::loadDashboard() 
{
    std::ifstream ifs(dashboardFile.c_str(), std::ios::binary);
    if (!ifs) 
    {
        throw std::runtime_error("Could not open file for loading dashboard." );
        return;
    }

    size_t userCount;
    ifs.read((char*)&userCount, sizeof(userCount));

    for (size_t i = 0; i < userCount; i++) 
    {
        size_t usernameLen;
        ifs.read((char*)&usernameLen, sizeof(usernameLen));
        char* usernameBuffer = new char[usernameLen + 1];
        ifs.read(usernameBuffer, usernameLen);
        usernameBuffer[usernameLen] = '\0';
        MyString username(usernameBuffer);
        delete[] usernameBuffer;

        User* user = findUser(username);
        if (!user)
        {
            throw std::runtime_error("User not found while loading dashboard.");
        }
        user->getDashboard().deserialize(ifs);
    }

    ifs.close();
    if (!ifs)
    {
        throw std::runtime_error("Could not read from dashboard file." );
    }
}