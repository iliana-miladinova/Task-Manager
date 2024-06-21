//#include "UserManager.h"
//
//UserManager::UserManager()
//{
//    loadUsers();
//}
//
//UserManager::~UserManager()
//{
//    saveUsers();
//}
//
//void UserManager::registerUser(const MyString& username, const MyString& password)
//{
//    for (size_t i = 0; i < users.getSize(); i++)
//    {
//        if (users[i].getUsername() == username)
//        {
//            throw std::invalid_argument("Username already exists!");
//        }
//    }
//    User newUser(username, password);
//    users.pushBack(newUser);
//
//    userCount++;
//    /*newUser.saveTasks();*/
//}
//
//User* UserManager::loginUser(const MyString& username, const MyString& password)
//{
//    for (size_t i = 0; i < users.getSize(); i++)
//    {
//        if (users[i].getUsername() == username)
//        {
//            if (users[i].checkPassword(password))
//            {
//                /*users[i].loadTasks();*/
//                return &users[i];
//            }
//            else
//            {
//                throw std::invalid_argument("Incorrect password!");
//            }
//        }
//    }
//    throw std::invalid_argument("User not found!");
//}
//
//void UserManager::loadUsers(/*const MyString& filename*/) {
//    std::ifstream ifs(filename.c_str(), std::ios::binary);
//    if (!ifs) {
//        throw std::runtime_error("Cannot open file for reading.");
//    }
//
//    /*size_t userCount;
//    ifs.read((char*)&userCount, sizeof(userCount));*/
//   /* size_t userCount;*/
//    ifs.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
//   /* if (ifs.fail()) {
//        throw std::runtime_error("Error reading user count from file.");
//    }*/
//
//    users.clear();
//
//    /*users.clear();*/
//    for (size_t i = 0; i < userCount; ++i) {
//       /* MyString userType;
//        userType.deserialize(ifs);*/
//
//        User user;
//        if (ifs.fail()) {
//            throw std::runtime_error("Error deserializing user from file.");
//        }
//        /*if (userType == "IndividualUser") {
//            user.reset(new IndividualUser());
//        } */// Добавяне на други типове потребители, ако има такива
//
//        user.deserializeUser(ifs);
//        users.pushBack(user);
//    }
//
//    ifs.close();
//}
//
//void UserManager::saveUsers(/*const MyString& filename*/) const {
//    std::ofstream ofs(filename.c_str(), std::ios::binary);
//    if (!ofs) {
//        throw std::runtime_error("Cannot open file for writing.");
//    }
//
//    /*size_t userCount = users.getSize();*/
//    ofs.write((const char*)&userCount, sizeof(userCount));
//
//    for (size_t i = 0; i < userCount; ++i) {
//       /* MyString userType = users[i]->getUserType();
//        userType.serialize(ofs);
//        users[i]->serializeUser(ofs);*/
//        users[i].serializeUser(ofs);
//    }
//}
//
////void UserManager::loadUsers()
////{
////    std::ifstream inFile(filename, std::ios::binary);
////    if (!inFile) return;
////
////    size_t usersCount;
////    inFile.read(reinterpret_cast<char*>(&usersCount), sizeof(usersCount));
////    users.clear();
////
////    for (size_t i = 0; i < usersCount; i++)
////    {
////        User user;
////        user.deserializeUser(inFile);
////        /*user.loadTasks();*/
////        users.pushBack(user);
////    }
////
////    inFile.close();
////}
//
////void UserManager::saveUsers() const
////{
////    std::ofstream outFile(filename, std::ios::binary);
////    if (!outFile) return;
////
////    size_t usersCount = users.getSize();
////    outFile.write(reinterpret_cast<const char*>(&usersCount), sizeof(usersCount));
////
////    for (size_t i = 0; i < usersCount; i++)
////    {
////        users[i].serializeUser(outFile);
////        /*users[i].saveTasks();*/
////    }
////
////    outFile.close();
//////}
//
// 
// 
// Raboti
#include "UserManager.h"
#include <fstream>

UserManager::UserManager() {
    loadUsers();
}

UserManager::~UserManager() {
    if (currentUser) {
        saveTasks(currentUser->getUsername());
    }
    saveUsers();
}

void UserManager::registerUser(const MyString& username, const MyString& password) {
    if (findUser(username) != nullptr) 
    {
        throw std::runtime_error("User with this username already exists");// User already exists
    }
    users.pushBack(User(username, password));
    saveUsers();
 /* ???  *//*saveTasks(username);*/
   /* return true;*/
}

void UserManager::loginUser(const MyString& username, const MyString& password) {
   /* for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i].getUsername() == username && users[i].checkPassword(password)) {
            return &users[i];
        }
    }*/
   // for (size_t i = 0; i < users.getSize(); ++i) {
   //     if (users[i].getUsername() == username && users[i].checkPassword(password)) {
   //         currentUser = &users[i];
   //     }
   // }
   // //User* user = findUser(username);
   // //if (user!=nullptr&&user->checkPassword(password))
   // //{
   // //    currentUser= /*&*/user;
   // //    loadTasks(username);
   // //}
   ///* else
   // {*/
   //     throw std::runtime_error("Invalid username or password!");
   ///* }*/

    User* user = findUser(username);
    if (user && user->checkPassword(password)) {
        currentUser = user;
        std::cout << "Welcome back, " << username << "!\n";
        loadTasks(username);
    }
    else {
        std::cout << "Invalid username or password!\n";
    }
}

void UserManager::logoutUser() {
    /*currentUser = nullptr;*/
    if (currentUser) {
        saveTasks(currentUser->getUsername());
        currentUser = nullptr;
    }
}

void UserManager::loadUsers() {
  /*  std::ifstream userIfs(userFile.c_str(), std::ios::binary);
    if (userIfs) {
        size_t userCount;
        userIfs.read((char*)&userCount, sizeof(userCount));
        users.clear();
        for (size_t i = 0; i < userCount; ++i) {
            User user;
            user.deserializeUser(userIfs);
            users.pushBack(user);
        }
    }*/

    std::ifstream ifs(userFile.c_str(), std::ios::binary);
    if (!ifs) return;

    size_t userCount;
    ifs.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
    for (size_t i = 0; i < userCount; ++i) {
        User user;
        user.deserializeUser(ifs);
        users.pushBack(user);
    }
    ifs.close();

    ///*std::ifstream taskIfs(taskFile.c_str(), std::ios::binary);
    //if (taskIfs) {
    //    for (size_t i = 0; i < users.getSize(); ++i) {
    //        users[i].deserializeTasks(taskIfs);
    //    }
    //}*/
}

void UserManager::saveUsers() /*const */{
    std::ofstream userOfs(userFile.c_str(), std::ios::binary);
    if (userOfs) {
        size_t userCount = users.getSize();
        userOfs.write((const char*)&userCount, sizeof(userCount));
        for (size_t i = 0; i < userCount; ++i) {
            users[i].serializeUser(userOfs);
        }
    }

   /* std::ofstream taskOfs(taskFile.c_str(), std::ios::binary);
    if (taskOfs) {
        for (size_t i = 0; i < users.getSize(); ++i) {
            users[i].serializeTasks(taskOfs);
        }
    }*/
}

void UserManager::loadTasks(const MyString& username)
{
    //std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    //if (ifs) {
    //    while (!ifs.eof()) {
    //        User tempUser;
    //        tempUser.deserializeUser(ifs);
    //        if (!ifs) break;
    //        if (tempUser.getUsername() == username) {
    //            currentUser->deserializeTasks(ifs);
    //            return;
    //        }
    //        else {
    //            tempUser.deserializeTasks(ifs);
    //            if (!ifs) break;// Skip other user's tasks
    //        }
    //    }
    //}

    /*std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    if (ifs) {
        while (!ifs.eof()) {
            User tempUser;
            tempUser.deserializeUser(ifs);
            if (tempUser.getUsername() == username) {
                currentUser = findUser(username);
                if (currentUser) {
                    currentUser->deserializeTasks(ifs);
                }
                break;
            }
            else {
                tempUser.deserializeTasks(ifs);
            }
        }
    }*/

    std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    if (!ifs) return;

    size_t taskCount;
    ifs.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        MyString user;
        size_t usernameLength;
        ifs.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
        char* usernameBuffer = new char[usernameLength + 1];
        ifs.read(usernameBuffer, usernameLength);
        usernameBuffer[usernameLength] = '\0';
        user = MyString(usernameBuffer);
        delete[] usernameBuffer;
        if (user == username) {
            currentUser->deserializeTasks(ifs);
        }
        else {
            size_t taskSize;
            ifs.read(reinterpret_cast<char*>(&taskSize), sizeof(taskSize));
            ifs.seekg(taskSize, std::ios::cur);
        }
    }
    ifs.close();

    /*!!!*/
    /*std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    if (ifs) {
        while (!ifs.eof()) {
            User tempUser;
            tempUser.deserializeUser(ifs);
            if (!ifs) break;
            if (tempUser.getUsername() == username) {
                currentUser->deserializeTasks(ifs);
                return;
            }
            else {
                tempUser.deserializeTasks(ifs);
                if (!ifs) break;
            }
        }
    }*/
}

void UserManager::saveTasks(const MyString& username)  {
  //  std::ifstream ifs(taskFile.c_str(), std::ios::binary);
  //  std::ofstream ofs("temp.dat", std::ios::binary);
  //  bool userFound = false;

  //  if (ifs&&ofs) {
  //      while (!ifs.eof()) {
  //          User tempUser;
  //          tempUser.deserializeUser(ifs);
  //          if (!ifs) break;
  //          if (tempUser.getUsername() == username) {
  //              currentUser->serializeUser(ofs);
  //              currentUser->serializeTasks(ofs);
  //              /*ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
  //              userFound = true;
  //              tempUser.deserializeTasks(ifs);
  //          }
  //          else {
  //              tempUser.serializeUser(ofs);
  //              tempUser.deserializeTasks(ifs);
  //              if (!ifs) break;
  //              tempUser.serializeTasks(ofs);
  //          }
  //      }
  //  }

  //  if (!userFound && currentUser) {
  //      currentUser->serializeUser(ofs);
  //      currentUser->serializeTasks(ofs);
  //  }

  //  ifs.close();
  //  ofs.close();
  /////* da se napravi bez tezi*/ remove(taskFile.c_str());
  /////* da se napravi bez tezi*/  rename("temp.dat", taskFile.c_str());
  //  if (!userFound && currentUser) 
  //  {
  //      std::ofstream ofs_app(taskFile.c_str(), std::ios::binary | std::ios::app);
  //      if (ofs_app) {
  //          currentUser->serializeUser(ofs_app);
  //          currentUser->serializeTasks(ofs_app);
  //          ofs_app.close();
  //      }
  //      else {
  //          throw std::runtime_error("Error while openning file for appending");
  //      }
  //  }

  /*  std::ofstream ofs(taskFile.c_str(), std::ios::binary | std::ios::app);
    if (ofs) {
        for (size_t i = 0; i < users.getSize(); ++i) {
            if (users[i].getUsername() == username) {
                users[i].serializeUser(ofs);
                users[i].serializeTasks(ofs);
            }
        }
    }*/
    std::ofstream ofs(taskFile.c_str(), std::ios::binary | std::ios::app);
    size_t usernameLength = username.getSize();
    ofs.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
    ofs.write(username.c_str(), usernameLength);

    size_t taskCount = currentUser->getTasks().getSize();
    ofs.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));
    currentUser->serializeTasks(ofs);
    ofs.close();
    /*!!!

    std::ifstream ifs(taskFile.c_str(), std::ios::binary);
    std::ofstream ofs("temp.dat", std::ios::binary);
    bool userFound = false;

    if (ifs && ofs) {
        while (!ifs.eof()) {
            User tempUser;
            tempUser.deserializeUser(ifs);
            if (!ifs) break;
            if (tempUser.getUsername() == username) {
                currentUser->serializeUser(ofs);
                currentUser->serializeTasks(ofs);
                userFound = true;
                tempUser.deserializeTasks(ifs);
            }
            else {
                tempUser.serializeUser(ofs);
                tempUser.deserializeTasks(ifs);
                if (!ifs) break;
                tempUser.serializeTasks(ofs);
            }
        }
    }

    if (!userFound && currentUser) {
        currentUser->serializeUser(ofs);
        currentUser->serializeTasks(ofs);
    }

    ifs.close();
    ofs.close();
    remove(taskFile.c_str());
    rename("temp.dat", taskFile.c_str());*/

}

User* UserManager::findUser(const MyString& username) 
{
    for (size_t i = 0; i < users.getSize(); i++) 
    {
        if (users[i].getUsername() == username) {
            return &users[i];
        }
    }
    return nullptr;
}

User* UserManager::getCurrentUser() const {
    return currentUser;
}

void UserManager::updateTaskName(int id, const MyString& name)
{
    if (currentUser) {
        currentUser->updateTaskName(id, name);
        saveTasks(currentUser->getUsername());
       /* saveUsers();*/ // Save users after updating the task name
    }
    else {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::updateTaskDescription(int id, const MyString& description) {
    if (currentUser) {
        currentUser->updateTaskDescription(id, description);
        saveTasks(currentUser->getUsername());
        /*saveUsers();*/ // Save users after updating the task description
    }
    else {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::removeTaskFromDashboard(int id) {
    if (currentUser) {
        currentUser->removeTaskFromDashboard(id);
        saveTasks(currentUser->getUsername());
       /* saveUsers();*/ // Save users after removing the task from the dashboard
    }
    else {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::addTaskToDashboard(int id) {
    if (currentUser) {
        currentUser->addTaskToDashboard(id);
        saveTasks(currentUser->getUsername());
       /* saveUsers();*/ // Save users after adding the task to the dashboard
    }
    else {
        throw std::runtime_error("No user is logged in!");
    }
}

void UserManager::deleteTask(int id) {
    if (currentUser) {
        currentUser->deleteTask(id);
        saveTasks(currentUser->getUsername());
        //saveUsers(); // Save users after deleting the task
    }
    else {
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
        currentUser->addTask(name,dueDate,description);
        saveTasks(currentUser->getUsername());
    }
    else
    {
        throw std::runtime_error("No user is logged in!");

    }
}