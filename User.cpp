#include "User.h"
#include "HelperFunctions.h"

User::User(const MyString& username, const MyString& password) : username(username), password(password) 
{

}

const MyString& User::getUsername() const
{
    return username;
}


void User::addTask(Polymorphic_Ptr<Task> task)
{
    for (size_t i = 0; i < tasks.getSize(); i++) 
    {
        if (task->getDueDate().containsData())
        {
            if (tasks[i]->getName() == task->getName() && tasks[i]->getDueDate().getData() == task->getDueDate().getData())
            {
                throw std::runtime_error("Task with this name already exists!");
            }
        }
    }
    tasks.pushBack(task);
    if (task->getDueDate().containsData() && HelperFunctions::isDueToday(task->getDueDateFromString())) 
    {
        dashboard.addTask(task);
    }
}

const Vector<Polymorphic_Ptr<Task>>& User::getTasks() const 
{
    return tasks;
}

void User::serializeUser(std::ofstream& ofs) const 
{
    size_t usernameLen = username.getSize();
    ofs.write((const char*)&usernameLen, sizeof(usernameLen));
    ofs.write(username.c_str(), usernameLen);

    size_t passwordLen = password.getSize();
    ofs.write((const char*)&passwordLen, sizeof(passwordLen));
    ofs.write(password.c_str(), passwordLen);
}

void User::deserializeUser(std::ifstream& ifs) 
{
    size_t usernameLen;
    ifs.read((char*)&usernameLen, sizeof(usernameLen));
    if (!ifs) throw std::runtime_error("Error reading username length");

    char* usernameBuffer = new char[usernameLen + 1];
    ifs.read(usernameBuffer, usernameLen);
    if (!ifs) {
        delete[] usernameBuffer;
        throw std::runtime_error("Error reading username");
    }
    usernameBuffer[usernameLen] = '\0';
    username = MyString(usernameBuffer);
    delete[] usernameBuffer;

    size_t passwordLen;
    ifs.read((char*)&passwordLen, sizeof(passwordLen));
    if (!ifs) throw std::runtime_error("Error reading password length");

    char* passwordBuffer = new char[passwordLen + 1];
    ifs.read(passwordBuffer, passwordLen);
    if (!ifs) {
        delete[] passwordBuffer;
        throw std::runtime_error("Error reading password");
    }
    passwordBuffer[passwordLen] = '\0';
    password = MyString(passwordBuffer);
    delete[] passwordBuffer;
   
}

void User::serializeTasks(std::ofstream& ofs) const
{

    size_t taskCount = tasks.getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++) 
    {
        char type;
        if (tasks[i]->getType() == "ProjectTask")
        {
            type = 'P';
        }
        else
        {
            type = 'T';
        }
        ofs.write(&type, 1);
        tasks[i]->serialize(ofs);
    }
    dashboard.serialize(ofs);
}

void User::deserializeTasks(std::ifstream& ifs)
{

    size_t taskCount;
    ifs.read((char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++)
    {
        char type;
        ifs.read(&type, sizeof(type));
        Polymorphic_Ptr<Task> task;
        if (type == 'P') 
        {
            task = Polymorphic_Ptr<Task>(new ProjectTask());
        }
        else 
        {
            task = Polymorphic_Ptr<Task>(new Task());
        }
        task->deserialize(ifs);
        tasks.pushBack(std::move(task));
    }
    dashboard.deserialize(ifs);

}

bool User::checkPassword(const MyString& password) const 
{
    return this->password == password;
}

void User::updateTaskName(int id, const MyString& name)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            tasks[i]->setName(name);
            return;
        }
    }
}

void User::startTask(int id)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            tasks[i]->startTask();
            return;
        }
    }
}

void User::updateTaskDescription(int id, const MyString& description)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            tasks[i]->setDescription(description);
            return;
        }
    }
}

void User::removeTaskFromDashboard(int id)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            dashboard.removeTask(i);
            return;

        }
    }
}

void User::addTaskToDashboard(int id)
{
    dashboard.addTaskById(id);
}

void User::deleteTask(int id)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            tasks.erase(i);
            return;
        }
    }
}

void User::getTask(const MyString& name) const
{
    Polymorphic_Ptr<Task> task = nullptr;
    bool found = false;
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getName() == name)
        {
            if (!found || tasks[i]->getId() < task->getId())
            {
                task = tasks[i];
                found = true;
            }
        }
    }
    if (found)
    {
        task->showTask();
    }
    else
    {
        throw std::runtime_error("Task is not found");
    }
}

void User::getTask(int id) const
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == id)
        {
            tasks[i]->showTask();
            return;
        }
    }
    throw std::runtime_error("Task is not found");
}

void User::listTasks(const MyString& dueDate) const
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
            if (tasks[i]->getDueDate().getData() == dueDate)
            {
                tasks[i]->showTask();
            }
    }
    throw std::runtime_error("Task is not found");
}

void User::listTasks() const
{
    if (tasks.getSize() == 0)
    {
        throw std::runtime_error("No tasks found");
    }

    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i])
        { 
            tasks[i]->showTask();
        }
        else 
        {
            throw std::runtime_error("Null pointer");
        }
    }

}

void User::listCompletedTasks() const
{
    bool found = false;
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getStatus() == Status::DONE)
        {
            tasks[i]->showTask();
            found = true;
        }
    }
    if (!found)
    {
        throw std::runtime_error("Task is not found");
    }

}

void User::addTask(const MyString& name, const MyString& dueDate, const MyString& description)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getName() == name && tasks[i]->getDueDate().getData() == dueDate)
        {
            throw std::runtime_error("Task with this name already exists!");
        }
    }
    Optional<MyString> optDueDate;
    if (dueDate.getSize() > 0)
    {
        optDueDate.setData(dueDate);
    }
    int newId;
    if (tasks.isEmpty())
    {
        newId = 1;
    }
    else
    {
        newId = tasks[tasks.getSize() - 1]->getId() + 1;
    }
    Polymorphic_Ptr<Task> newTask = Polymorphic_Ptr<Task>(new Task(newId, name, optDueDate, Status::ON_HOLD, description));
    addTask(newTask);
    if (HelperFunctions::isDueToday(newTask->getDueDateFromString())) 
    {
        dashboard.addTask(newTask);
    }
}

const Dashboard& User::getDashboard() const
{
    return dashboard;
}

Dashboard& User::getDashboard()
{
    return dashboard;
}


void User::finishTask(int id) 
{
    for (size_t i = 0; i < tasks.getSize(); i++) 
    {
        if (tasks[i]->getId() == id) 
        {
            tasks[i]->setStatus(Status::DONE);
            return;
        }
    }
    throw std::runtime_error("Task not found!");
}
