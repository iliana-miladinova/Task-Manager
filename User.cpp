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

//const MyString& User::getPassword() const {
//    return password;
//}

void User::addTask(Polymorphic_Ptr<Task> task) 
{
    /*tasks.pushBack(task);*/
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getName() == task->getName() && tasks[i]->getDueDate()==task->getName())
        {
            throw std::runtime_error("Task with this name already exists!");
        }
    }
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
    /*size_t usernameLen;
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
    delete[] passwordBuffer;*/

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

void User::serializeTasks(std::ofstream& ofs) const {
    size_t taskCount = tasks.getSize();
    ofs.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        char type = tasks[i]->getType() == "ProjectTask" ? 'P' : 'T';
        ofs.write(&type, 1);
        tasks[i]->serialize(ofs);
    }
    dashboard.serialize(ofs);

    //size_t taskCount = tasks.getSize();
    //ofs.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));
    //for (size_t i = 0; i < taskCount; ++i) {
    //    char type = tasks[i]->getType() == "ProjectTask" ? 'P' : 'T';
    //    ofs.write(&type, 1);
    //    tasks[i]->serialize(ofs);
    //}
    //dashboard.serialize(ofs);
}

void User::deserializeTasks(std::ifstream& ifs) {
   
    /*size_t taskCount;
    ifs.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        char type;
        ifs.read(&type, 1);
        Polymorphic_Ptr<Task> task;
        if (type == 'P') {
            task = Polymorphic_Ptr<Task>(new ProjectTask());
        }
        else {
            task = Polymorphic_Ptr<Task>(new Task());
        }
        task->deserialize(ifs);
        tasks.pushBack(std::move(task));
    }
    dashboard.deserialize(ifs);*/
    size_t taskCount;
    ifs.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        char type;
        ifs.read(&type, 1);
        Polymorphic_Ptr<Task> task;
        if (type == 'P') {
            task = Polymorphic_Ptr<Task>(new ProjectTask());
        }
        else {
            task = Polymorphic_Ptr<Task>(new Task());
        }
        task->deserialize(ifs);
        tasks.pushBack(std::move(task));
    }
    dashboard.deserialize(ifs);

}

bool User::checkPassword(const MyString& password) const {
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
        if (tasks[i]->getId()==id)
        {/*
            tasks[i]->setStatus(Status::IN_PROCESS);*/
            tasks[i]->startTask();
            return;
        }
    }
}

void User::updateTaskDescription(int id, const MyString& description)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId()==id)
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
        if (tasks[i]->getId()==id)
        {
            dashboard.removeTask(i);
            return;
           
        }
    }
}

void User::addTaskToDashboard(int id)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId()==id)
        {
            throw std::logic_error("Task already exists!");
            /*if (tasks[i]->getStatus()!=Status::OVERDUE)
            {
                dashboard.addTaskById(i);
            }*/
        }
    }
    dashboard.addTaskById(id);
}

void User::deleteTask(int id)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId()==id)
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
            if (!found||tasks[i]->getId()<task->getId())
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
        if (tasks[i]->getId()==id)
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
        if (tasks[i]->getDueDate()==dueDate)
        {
            tasks[i]->showTask();
        }
    }
    throw std::runtime_error("Task is not found");
}

void User::listTasks() const
{
 //   for (size_t i = 0; i < tasks.getSize(); i++)
 //   {
 //       tasks[i]->showTask();
 //   }
 ///*   ????*/throw std::runtime_error("Task is not found");

    if (tasks.getSize() == 0) {
        throw std::runtime_error("No tasks found");
    }

    for (size_t i = 0; i < tasks.getSize(); ++i) {
        if (tasks[i]) {  // Проверка дали указателят не е null
            tasks[i]->showTask();
        }
        else {
            std::cerr << "Warning: Null task pointer encountered at index " << i << std::endl;
        }
    }
    //if (tasks.getSize() == 0)
    //{
    //    throw std::runtime_error("No tasks found");
    //}

    //for (size_t i = 0; i < tasks.getSize(); i++)
    //{
    //    tasks[i]->showTask();
    //}

}

void User::listCompletedTasks() const
{
    bool found = false;
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getStatus()==Status::DONE)
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
        if (tasks[i]->getName() == name && tasks[i]->getDueDate() == dueDate)
        {
            throw std::runtime_error("Task with this name already exists!");
        }
    }
    Polymorphic_Ptr<Task> task = Polymorphic_Ptr<Task>(new Task(tasks.getSize() + 1, name, dueDate, Status::ON_HOLD, description));
    tasks.pushBack(task);
    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
        dashboard.addTask(task);
    }

}