#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "MyString.h"
#include <fstream>
#include "Collaboration.h"

class UserManager 
{
private:
    Vector<User> users;
    User* currentUser = nullptr;
    const MyString userFile = "users.dat"; 
    const MyString taskFile = "tasks.dat"; 
    const MyString collabFile = "collaborations.dat"; 
    MyString dashboardFile = "dashboard.dat";
    Vector<Collaboration> collaborations;

    void loadUsers();
    void saveUsers() const;
    void loadCollaborations();
    void saveCollaborations() const;
    void loadTasks(const MyString& username);
    void saveTasks(const MyString& username) const;
    void saveDashboard() const;
    void loadDashboard();

public:
    UserManager();
    ~UserManager();

    void registerUser(const MyString& username, const MyString& password);
    void loginUser(const MyString& username, const MyString& password);
    void logoutUser();

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

    void listDashboard() const;

    void finishTask(int id);

    const Collaboration* findCollaborationByName(const MyString& name) const;

    Collaboration* findCollaborationByName(const MyString& name);

    void addCollaboration(const MyString& name);

    void deleteCollaboration(const MyString& name);

    void listCollaborations() const;

    void addUserToCollaboration(const MyString& collabName, const MyString& username);

    void assignTaskToCollaboration(const MyString& collabName, const MyString& username, const MyString& name, const MyString& dueDate, const MyString& description);

    void listCollaborationTasks(const MyString& collabName) const;

    User* getCurrentUser() const;
};
