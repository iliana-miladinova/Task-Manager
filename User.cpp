//#include "User.h"
//
//User::User(const MyString& username, const MyString& password) :username(username), password(password)
//{
//
//}
//
//const MyString& User::getUsername() const
//{
//    return username;
//}
//
//const MyString& User::getPassword() const
//{
//    return password;
//}
//
//void User::serializeUser(std::ofstream& ofs) const
//{
//    size_t usernameLen = username.getSize();
//    ofs.write((const char*)&usernameLen, sizeof(usernameLen));
//    ofs.write(username.c_str(), usernameLen);
//    size_t passwordLen = password.getSize();
//    ofs.write((const char*)&passwordLen, sizeof(passwordLen));
//    ofs.write(password.c_str(), passwordLen);
//
//    dashboard.serialize(ofs);
//
//    size_t taskCount = tasks.getSize();
//    ofs.write((const char*)&taskCount, sizeof(taskCount));
//    for (size_t i = 0; i < taskCount; ++i) {
//        tasks[i]->serialize(ofs);
//    }
//
//}
//
//void User::deserializeUser(std::ifstream& ifs)
//{
//    size_t usernameLen;
//    ifs.read((char*)&usernameLen, sizeof(usernameLen));
//    char* usernameBuffer = new char[usernameLen + 1];
//    ifs.read(usernameBuffer, usernameLen);
//    usernameBuffer[usernameLen] = '\0';
//    username = MyString(usernameBuffer);
//    delete[] usernameBuffer;
//
//    size_t passwordLen;
//    ifs.read((char*)&passwordLen, sizeof(passwordLen));
//    char* passwordBuffer = new char[passwordLen + 1];
//    ifs.read(passwordBuffer, passwordLen);
//    passwordBuffer[passwordLen] = '\0';
//    password = MyString(passwordBuffer);
//    delete[] passwordBuffer;
//
//
//    /*size_t taskCount;*/
//   /*ifs.read((char*)&taskCount, sizeof(taskCount));
//    tasks.clear();
//    for (size_t i = 0; i < taskCount; ++i) {
//        MyString taskType;
//        taskType.deserialize(ifs);
//
//        Polymorphic_Ptr<Task> task;
//        if (taskType == "Task") {
//            task.reset(new Task());
//        }
//        else if (taskType == "ProjectTask") {
//            task.reset(new ProjectTask());
//        }
//        task->deserialize(ifs);
//        tasks.pushBack(task);
//    }*/
//    size_t taskCount;
//    ifs.read((char*)&taskCount, sizeof(taskCount));
//    tasks.clear();
//    for (size_t i = 0; i < taskCount; ++i) {
//        MyString taskType;
//        size_t taskTypeLen;
//        ifs.read((char*)&taskTypeLen, sizeof(taskTypeLen));
//        char* taskTypeBuffer = new char[taskTypeLen + 1];
//        ifs.read(taskTypeBuffer, taskTypeLen);
//        taskTypeBuffer[taskTypeLen] = '\0';
//        taskType = MyString(taskTypeBuffer);
//        delete[] taskTypeBuffer;
//
//        Polymorphic_Ptr<Task> task;
//        if (taskType == "Task") {
//            task.reset(new Task());
//        }
//        else if (taskType == "ProjectTask") {
//            task.reset(new ProjectTask());
//        }
//        task->deserialize(ifs);
//        tasks.pushBack(task);
//    }
//
//}
//
//
//bool User::checkPassword(const MyString& password) const
//{
//    return this->password == password;
//}
//
//void User::addTask(Polymorphic_Ptr<Task> task) {
//    tasks.pushBack(task);
//    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
//        dashboard.addTask(task);
//    }
//}
//
//const Vector<Polymorphic_Ptr<Task>>& User::getTasks() const {
//    return tasks;
//}
//
//const Vector<Polymorphic_Ptr<Task>>& User::getDashboardTasks() const {
//    return dashboard.getTasks();
//}
//
//void User::updateDashboard()
//{
//    dashboard.update(tasks);
//}
//
//void User::login()
//{
//    dashboard.loadFromFile(/*username*/);
//    updateDashboard();
//}
//
//void User::removeTaskFromDashboard(int taskId)
//{
//    dashboard.removeTask(taskId);
//}

//#include "User.h"
//#include "HelperFunctions.h"
//
//User::User(const MyString& username, const MyString& password)
//    : username(username), password(password), dashboard(dashboard) {}
//
//const MyString& User::getUsername() const {
//    return username;
//}
//
//const MyString& User::getPassword() const {
//    return password;
//}
//
//void User::addTask(Polymorphic_Ptr<Task> task) {
//    tasks.pushBack(task);
//    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
//        dashboard.addTask(task);
//    }
//}
//
//const Vector<Polymorphic_Ptr<Task>>& User::getTasks() const {
//    return tasks;
//}
//
//void User::serializeUser(std::ofstream& ofs) const {
//    size_t usernameLen = username.getSize();
//    ofs.write((const char*)&usernameLen, sizeof(usernameLen));
//    ofs.write(username.c_str(), usernameLen);
//
//    size_t passwordLen = password.getSize();
//    ofs.write((const char*)&passwordLen, sizeof(passwordLen));
//    ofs.write(password.c_str(), passwordLen);
//}
//
//void User::deserializeUser(std::ifstream& ifs) {
//    size_t usernameLen;
//    ifs.read((char*)&usernameLen, sizeof(usernameLen));
//    char* usernameBuffer = new char[usernameLen + 1];
//    ifs.read(usernameBuffer, usernameLen);
//    usernameBuffer[usernameLen] = '\0';
//    username = MyString(usernameBuffer);
//    delete[] usernameBuffer;
//
//    size_t passwordLen;
//    ifs.read((char*)&passwordLen, sizeof(passwordLen));
//    char* passwordBuffer = new char[passwordLen + 1];
//    ifs.read(passwordBuffer, passwordLen);
//    passwordBuffer[passwordLen] = '\0';
//    password = MyString(passwordBuffer);
//    delete[] passwordBuffer;
//}
//
//void User::serializeTasks(std::ofstream& ofs) const {
//    size_t taskCount = tasks.getSize();
//    ofs.write((const char*)&taskCount, sizeof(taskCount));
//    for (size_t i = 0; i < taskCount; ++i) {
//        tasks[i]->serialize(ofs);
//    }
//}
//
//void User::deserializeTasks(std::ifstream& ifs)
//{
//    size_t taskCount;
//    ifs.read((char*)&taskCount, sizeof(taskCount));
//    tasks.clear();
//    for (size_t i = 0; i < taskCount; ++i) {
//        MyString taskType;
//        size_t taskTypeLen;
//        ifs.read((char*)&taskTypeLen, sizeof(taskTypeLen));
//        char* taskTypeBuffer = new char[taskTypeLen + 1];
//        ifs.read(taskTypeBuffer, taskTypeLen);
//        taskTypeBuffer[taskTypeLen] = '\0';
//        taskType = MyString(taskTypeBuffer);
//        delete[] taskTypeBuffer;
//
//        Polymorphic_Ptr<Task> task;
//        if (taskType == "Task") {
//            task.reset(new Task());
//        }
//        else if (taskType == "ProjectTask") {
//            task.reset(new ProjectTask());
//        }
//        task->deserialize(ifs);
//        tasks.pushBack(task);
//    }
//}
//
//bool User::checkPassword(const MyString& password) const {
//    return this->password == password;
//}


//#include "User.h"
//#include "HelperFunctions.h"
//
//User::User(const MyString& username, const MyString& password)
//    : username(username), password(password) {}
//
//const MyString& User::getUsername() const {
//    return username;
//}
//
//const MyString& User::getPassword() const {
//    return password;
//}
//
//void User::addTask(Polymorphic_Ptr<Task> task) {
//    tasks.pushBack(task);
//    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
//        dashboard.addTask(task);
//    }
//}
//
//const Vector<Polymorphic_Ptr<Task>>& User::getTasks() const {
//    return tasks;
//}
//
//void User::serializeUser(std::ofstream& ofs) const {
//    size_t usernameLen = username.getSize();
//    ofs.write((const char*)&usernameLen, sizeof(usernameLen));
//    ofs.write(username.c_str(), usernameLen);
//
//    size_t passwordLen = password.getSize();
//    ofs.write((const char*)&passwordLen, sizeof(passwordLen));
//    ofs.write(password.c_str(), passwordLen);
//}
//
//void User::deserializeUser(std::ifstream& ifs) {
//    size_t usernameLen;
//    ifs.read((char*)&usernameLen, sizeof(usernameLen));
//    char* usernameBuffer = new char[usernameLen + 1];
//    ifs.read(usernameBuffer, usernameLen);
//    usernameBuffer[usernameLen] = '\0';
//    username = MyString(usernameBuffer);
//    delete[] usernameBuffer;
//
//    size_t passwordLen;
//    ifs.read((char*)&passwordLen, sizeof(passwordLen));
//    char* passwordBuffer = new char[passwordLen + 1];
//    ifs.read(passwordBuffer, passwordLen);
//    passwordBuffer[passwordLen] = '\0';
//    password = MyString(passwordBuffer);
//    delete[] passwordBuffer;
//}
//
//void User::serializeTasks(std::ofstream& ofs) const {
//    size_t taskCount = tasks.getSize();
//    ofs.write((const char*)&taskCount, sizeof(taskCount));
//    for (size_t i = 0; i < taskCount; ++i) {
//        tasks[i]->serialize(ofs);
//    }
//}
//
//void User::deserializeTasks(std::ifstream& ifs) {
//    size_t taskCount;
//    ifs.read((char*)&taskCount, sizeof(taskCount));
//    tasks.clear();
//    for (size_t i = 0; i < taskCount; ++i) {
//        MyString taskType;
//        size_t taskTypeLen;
//        ifs.read((char*)&taskTypeLen, sizeof(taskTypeLen));
//        char* taskTypeBuffer = new char[taskTypeLen + 1];
//        ifs.read(taskTypeBuffer, taskTypeLen);
//        taskTypeBuffer[taskTypeLen] = '\0';
//        taskType = MyString(taskTypeBuffer);
//        delete[] taskTypeBuffer;
//
//        Polymorphic_Ptr<Task> task;
//        if (taskType == "Task") {
//            task.reset(new Task());
//        }
//        else if (taskType == "ProjectTask") {
//            task.reset(new ProjectTask());
//        }
//        task->deserialize(ifs);
//        tasks.pushBack(task);
//    }
//}
//
//bool User::checkPassword(const MyString& password) const {
//    return this->password == password;
//}


#include "User.h"
#include "HelperFunctions.h"

User::User(const MyString& username, const MyString& password)
    : username(username), password(password) {}

const MyString& User::getUsername() const {
    return username;
}

const MyString& User::getPassword() const {
    return password;
}

void User::addTask(Polymorphic_Ptr<Task> task) {
    tasks.pushBack(task);
    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
        dashboard.addTask(task);
    }
}

const Vector<Polymorphic_Ptr<Task>>& User::getTasks() const {
    return tasks;
}

void User::serializeUser(std::ofstream& ofs) const {
    size_t usernameLen = username.getSize();
    ofs.write((const char*)&usernameLen, sizeof(usernameLen));
    ofs.write(username.c_str(), usernameLen);

    size_t passwordLen = password.getSize();
    ofs.write((const char*)&passwordLen, sizeof(passwordLen));
    ofs.write(password.c_str(), passwordLen);
}

void User::deserializeUser(std::ifstream& ifs) {
    size_t usernameLen;
    ifs.read((char*)&usernameLen, sizeof(usernameLen));
    char* usernameBuffer = new char[usernameLen + 1];
    ifs.read(usernameBuffer, usernameLen);
    usernameBuffer[usernameLen] = '\0';
    username = MyString(usernameBuffer);
    delete[] usernameBuffer;

    size_t passwordLen;
    ifs.read((char*)&passwordLen, sizeof(passwordLen));
    char* passwordBuffer = new char[passwordLen + 1];
    ifs.read(passwordBuffer, passwordLen);
    passwordBuffer[passwordLen] = '\0';
    password = MyString(passwordBuffer);
    delete[] passwordBuffer;
}

void User::serializeTasks(std::ofstream& ofs) const {
    size_t taskCount = tasks.getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        tasks[i]->serialize(ofs);
    }
}

void User::deserializeTasks(std::ifstream& ifs) {
    size_t taskCount;
    ifs.read((char*)&taskCount, sizeof(taskCount));
    tasks.clear();
    for (size_t i = 0; i < taskCount; ++i) {
        MyString taskType;
        size_t taskTypeLen;
        ifs.read((char*)&taskTypeLen, sizeof(taskTypeLen));
        char* taskTypeBuffer = new char[taskTypeLen + 1];
        ifs.read(taskTypeBuffer, taskTypeLen);
        taskTypeBuffer[taskTypeLen] = '\0';
        taskType = MyString(taskTypeBuffer);
        delete[] taskTypeBuffer;

        Polymorphic_Ptr<Task> task;
        if (taskType == "Task") {
            task.reset(new Task());
        }
        else if (taskType == "ProjectTask") {
            task.reset(new ProjectTask());
        }
        task->deserialize(ifs);
        tasks.pushBack(task);
    }
}

bool User::checkPassword(const MyString& password) const {
    return this->password == password;
}