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
    saveUsers();
}

void UserManager::registerUser(const MyString& username, const MyString& password) {
    users.pushBack(User(username, password));
}

User* UserManager::loginUser(const MyString& username, const MyString& password) {
    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i].getUsername() == username && users[i].checkPassword(password)) {
            return &users[i];
        }
    }
    return nullptr;
}

void UserManager::loadUsers() {
    std::ifstream userIfs(userFile.c_str(), std::ios::binary);
    if (userIfs) {
        size_t userCount;
        userIfs.read((char*)&userCount, sizeof(userCount));
        users.clear();
        for (size_t i = 0; i < userCount; ++i) {
            User user;
            user.deserializeUser(userIfs);
            users.pushBack(user);
        }
    }

    std::ifstream taskIfs(taskFile.c_str(), std::ios::binary);
    if (taskIfs) {
        for (size_t i = 0; i < users.getSize(); ++i) {
            users[i].deserializeTasks(taskIfs);
        }
    }
}

void UserManager::saveUsers() const {
    std::ofstream userOfs(userFile.c_str(), std::ios::binary);
    if (userOfs) {
        size_t userCount = users.getSize();
        userOfs.write((const char*)&userCount, sizeof(userCount));
        for (size_t i = 0; i < userCount; ++i) {
            users[i].serializeUser(userOfs);
        }
    }

    std::ofstream taskOfs(taskFile.c_str(), std::ios::binary);
    if (taskOfs) {
        for (size_t i = 0; i < users.getSize(); ++i) {
            users[i].serializeTasks(taskOfs);
        }
    }
}