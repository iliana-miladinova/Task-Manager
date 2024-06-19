#pragma once
#include "MyVector.hpp"
#include "IndividualUser.h"
#include "MyString.h"

//class UserManager 
//{
//private:
//    Vector<IndividualUser> users;
//    const MyString& filename = "users.dat"; // File for storing users
//
//public:
//    UserManager();
//    ~UserManager();
//
//    void registerUser(const MyString& username, const MyString& password);
//    IndividualUser* loginUser(const MyString& username, const MyString& password);
//
//    void loadUsers();
//    void saveUsers() const;
//};


class UserManager {
private:
    Vector<IndividualUser> users;
    const MyString& filename = "users.dat"; // File for storing users

public:
    UserManager();
    ~UserManager();

    void registerUser(const MyString& username, const MyString& password);
    IndividualUser* loginUser(const MyString& username, const MyString& password);

    void loadUsers();
    void saveUsers() const;
};
