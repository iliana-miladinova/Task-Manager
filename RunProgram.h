#pragma once
#include "UserManager.h"
#include "MyString.h"
#include <iostream>
#include <sstream>

class RunProgram
{
public:
    void run();

private:
    UserManager userManager;
    void processCommand(const MyString& command);
    void registerUser(const MyString& username, const MyString& password);
    void loginUser(const MyString& username, const MyString& password);
    void addTask(const MyString& name, const MyString& dueDate, const MyString& description);
    void getTask(const MyString& identifier);
    void updateTaskName(int id, const MyString& name);
    void startTask(int id);
    void updateTaskDescription(int id, const MyString& description);
    void removeTaskFromDashboard(int id);
    void addTaskToDashboard(int id);
    void deleteTask(int id);
    void listTasks(const Optional<MyString>& date = Optional<MyString>());
    void listCompletedTasks();
    void listDashboard();
    void finishTask(int id);
    void logout();
    void addCollaboration(const MyString& name);
    void deleteCollaboration(const MyString& name);
    void listCollaborations() const;
    void addUserToCollaboration(const MyString& collabName, const MyString& username);
    void assignTaskToCollaboration(const MyString& collabName, const MyString& username, const MyString& taskName, const MyString& dueDate, const MyString& description);
    void listCollaborationTasks(const MyString& collabName) const;
};