////#include "UserManager.h"
////#include <fstream>
////#include <iostream>
////
////UserManager::UserManager() {
////    loadUsers();
////}
////
////UserManager::~UserManager() {
////    saveUsers();
////}
////
////void UserManager::registerUser(const MyString& username, const MyString& password) {
////    for (size_t i = 0; i < users.getSize(); ++i) {
////        if (users[i].getUsername() == username) {
////            std::cout << "Username already exists. Try a different one.\n";
////            return;
////        }
////    }
////    IndividualUser newUser(username, password);
////    users.pushBack(newUser);
////    saveUsers();
////    std::cout << "User registered successfully.\n";
////}
////
////IndividualUser* UserManager::loginUser(const MyString& username, const MyString& password) {
////    for (size_t i = 0; i < users.getSize(); ++i) {
////        if (users[i].getUsername() == username && users[i].getPassword() == password) {
////            return &users[i];
////        }
////    }
////    return nullptr;
////}
////
////void UserManager::loadUsers() {
////    std::ifstream ifs(filename.c_str(), std::ios::binary);
////    if (ifs.is_open()) {
////        while (!ifs.eof()) {
////            IndividualUser user;
////            user.deserializeUser(ifs);
////            if (!ifs.eof()) {
////                users.pushBack(user);
////            }
////        }
////        ifs.close();
////    }
////}
////
////void UserManager::saveUsers() const {
////    std::ofstream ofs(filename.c_str(), std::ios::binary);
////    for (size_t i = 0; i < users.getSize(); ++i) {
////        users[i].serializeUser(ofs);
////    }
////    ofs.close();
////}
//
//#include "UserManager.h"
////#include <fstream>
////#include <iostream>
////
////UserManager::UserManager() {
////    loadUsers();
////}
////
////UserManager::~UserManager() {
////    saveUsers();
////}
////
////void UserManager::registerUser(const MyString& username, const MyString& password) {
////    for (size_t i = 0; i < users.getSize(); i++) {
////        if (users[i].getUsername() == username) {
////            throw std::invalid_argument("Username already exists!");
////        }
////    }
////    IndividualUser newUser(username, password);
////    users.pushBack(newUser);
////    newUser.saveTasks();
////    newUser.saveDashboard();
////    std::cout << "User registered successfully.\n";
////}
////
////IndividualUser* UserManager::loginUser(const MyString& username, const MyString& password) {
////    for (size_t i = 0; i < users.getSize(); i++) {
////        if (users[i].getUsername() == username) {
////            if (users[i].checkPassword(password)) {
////                users[i].loadTasks();
////                users[i].login();
////                return &users[i];
////            }
////            else {
////                throw std::invalid_argument("Incorrect password!");
////            }
////        }
////    }
////    throw std::invalid_argument("User not found!");
////}
////
////void UserManager::loadUsers() {
////    std::ifstream inFile(filename, std::ios::binary);
////    if (!inFile) return;
////
////    size_t usersCount;
////    inFile.read(reinterpret_cast<char*>(&usersCount), sizeof(usersCount));
////    users.clear();
////
////    for (size_t i = 0; i < usersCount; i++) {
////        IndividualUser user;
////        user.deserializeUser(inFile);
////        user.loadTasks();
////        user.login();
////        users.pushBack(user);
////    }
////
////    inFile.close();
////}
////
////void UserManager::saveUsers() const {
////    std::ofstream outFile(filename, std::ios::binary);
////    if (!outFile) return;
////
////    size_t usersCount = users.getSize();
////    outFile.write(reinterpret_cast<const char*>(&usersCount), sizeof(usersCount));
////
////    for (size_t i = 0; i < usersCount; i++) {
////        users[i].serializeUser(outFile);
////        users[i].saveTasks();
////        users[i].saveDashboard();
////    }
////
////    outFile.close();
////}
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
//    IndividualUser newUser(username, password);
//    users.pushBack(newUser);
//    newUser.saveTasks();
//}
//
//IndividualUser* UserManager::loginUser(const MyString& username, const MyString& password)
//{
//    for (size_t i = 0; i < users.getSize(); i++)
//    {
//        if (users[i].getUsername() == username)
//        {
//            if (users[i].checkPassword(password))
//            {
//                users[i].loadTasks();
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
//void UserManager::loadUsers()
//{
//    std::ifstream inFile(filename.c_str(), std::ios::binary);
//    if (!inFile) return;
//
//    size_t usersCount;
//    inFile.read(reinterpret_cast<char*>(&usersCount), sizeof(usersCount));
//    users.clear();
//
//    for (size_t i = 0; i < usersCount; i++)
//    {
//        IndividualUser user;
//        user.deserialize(inFile);
//        user.loadTasks();
//        users.pushBack(user);
//    }
//
//    inFile.close();
//}
//
//void UserManager::saveUsers() const
//{
//    std::ofstream outFile(filename.c_str(), std::ios::binary);
//    if (!outFile) return;
//
//    size_t usersCount = users.getSize();
//    outFile.write(reinterpret_cast<const char*>(&usersCount), sizeof(usersCount));
//
//    for (size_t i = 0; i < usersCount; i++)
//    {
//        users[i].serialize(outFile);
//        users[i].saveTasks();
//    }
//
//    outFile.close();
//}

#include "UserManager.h"
#include <fstream>
#include <iostream>

UserManager::UserManager() {
    loadUsers();
}

UserManager::~UserManager() {
    saveUsers();
}

void UserManager::registerUser(const MyString& username, const MyString& password) {
    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i].getUsername() == username) {
            std::cout << "Username already exists. Try a different one.\n";
            return;
        }
    }
    IndividualUser newUser(username, password);
    users.pushBack(newUser);
    saveUsers();
    std::cout << "User registered successfully.\n";
}

IndividualUser* UserManager::loginUser(const MyString& username, const MyString& password) {
    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            return &users[i];
        }
    }
    return nullptr;
}

void UserManager::loadUsers() {
    std::ifstream ifs(filename.c_str(), std::ios::binary);
    if (ifs.is_open()) {
        while (!ifs.eof()) {
            IndividualUser user;
            user.deserializeUser(ifs);
            if (!ifs.eof()) {
                users.pushBack(user);
            }
        }
        ifs.close();
    }
}

void UserManager::saveUsers() const {
    std::ofstream ofs(filename.c_str(), std::ios::binary);
    for (size_t i = 0; i < users.getSize(); ++i) {
        users[i].serializeUser(ofs);
    }
    ofs.close();
}