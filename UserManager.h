#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "MyString.h"
#include <fstream>

//class UserManager /*: public User*/
////{
////private:
////    Vector<User> users;
////    const MyString filename = "users.dat"; // File for storing users
////
////    /*???*/size_t userCount = 0;
////
////public:
////    UserManager();
////    ~UserManager();
////
////    void registerUser(const MyString& username, const MyString& password);
////    User* loginUser(const MyString& username, const MyString& password);
////
////    void loadUsers();
////    void saveUsers() const;
//};



class UserManager {
private:
    Vector<User> users;
    User* currentUser = nullptr;
    const MyString userFile = "users.dat"; // File for storing usernames and passwords
    const MyString taskFile = "tasks.dat"; // File for storing tasks and dashboards

public:
    UserManager();
    ~UserManager();

    void registerUser(const MyString& username, const MyString& password);
    void loginUser(const MyString& username, const MyString& password);
    void logoutUser();

    void loadUsers();
    void saveUsers() /*const*/;

    void loadTasks(const MyString& username);
    void saveTasks(const MyString& username) /*const*/;

    User* findUser(const MyString& username);

    void updateTaskName(int id, const MyString& name);

    void updateTaskDescription(int id, const MyString& description);

    void removeTaskFromDashboard(int id);

    void addTaskToDashboard(int id);

    void startTask(int id);

    void addTask(const MyString& name, const MyString& dueDate, const MyString& description);

    void deleteTask(int id);

    void getTask(const MyString& name) const;

    void getTask(int id) const;

    void listTasks(const MyString& dueDate) const;

    void listTasks() const;

    void listCompletedTasks() const;

    User* getCurrentUser() const;
};

//class UserManager {
//private:
//    Vector<User> users;
//    User* loggedInUser = nullptr;
//
//public:
//    bool registerUser(const MyString& username, const MyString& password) {
//        for (size_t i = 0; i < users.getSize(); i++) {
//            if (users[i].getUsername() == username) {
//                return false; // Username already exists
//            }
//        }
//        users.pushBack(User(username, password));
//        return true;
//    }
//
//    bool login(const MyString& username, const MyString& password) {
//        for (/*User& user : users*/size_t i = 0; i < users.getSize();i++) {
//            if (users[i].getUsername() == username && users[i].getPassword() == password) {
//                loggedInUser = &users[i];
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void logout() {
//        loggedInUser = nullptr;
//    }
//
//    User* getLoggedInUser() {
//        return loggedInUser;
//    }
//
//    void serialize(const std::string& filename) const {
//        std::ofstream ofs(filename, std::ios::binary);
//        if (ofs) {
//            size_t userCount = users.getSize();
//            ofs.write(reinterpret_cast<const char*>(&userCount), sizeof(userCount));
//            for (size_t i = 0; i < userCount; i++) {
//                users[i].serializeUser(ofs);
//            }
//        }
//    }
//
//    void deserialize(const std::string& filename) {
//        std::ifstream ifs(filename, std::ios::binary);
//        if (ifs) {
//            size_t userCount;
//            ifs.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
//            users.resize(userCount);
//            for (size_t i = 0; i < userCount; i++) {
//                users[i].deserializeUser(ifs);
//            }
//        }
//    }
//
//    void showDashboardForUser(const User& user)
//    {
//       /* Dashboard::showTasks();*/
//    }
//};