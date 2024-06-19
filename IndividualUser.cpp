#include "IndividualUser.h"

IndividualUser::IndividualUser(const MyString& username, const MyString& password)
    : User(username, password), dashboard(username) {}

void IndividualUser::addTask(Polymorphic_Ptr<Task>task) {
    tasks.pushBack(task);
    if (HelperFunctions::isDueToday(task->getDueDateFromString())) {
        dashboard.addTask(task);
    }
}

void IndividualUser::removeTaskFromDashboard(int taskId) 
{
    dashboard.removeTask(taskId);
}

const Vector<Polymorphic_Ptr<Task>>& IndividualUser::getTasks() const {
    return tasks;
}

const Vector<Polymorphic_Ptr<Task>>& IndividualUser::getDashboardTasks() const 
{
    return dashboard.getTasks();
}

void IndividualUser::updateDashboard() 
{
    dashboard.update(tasks);
}

void IndividualUser::login() 
{
    dashboard.loadFromFile(/*username*/);
    updateDashboard();
}

void IndividualUser::serializeUser(std::ofstream& ofs) const {
    User::serializeUser(ofs);

    size_t tasksCount = tasks.getSize();
    ofs.write((const char*)&tasksCount, sizeof(tasksCount));
    for (size_t i = 0; i < tasksCount; ++i) {
        tasks[i]->serialize(ofs);
    }
}

void IndividualUser::deserializeUser(std::ifstream& ifs) {
    User::deserializeUser(ifs);

    size_t tasksCount;
    ifs.read((char*)&tasksCount, sizeof(tasksCount));
    tasks.clear();
    for (size_t i = 0; i < tasksCount; ++i) {
        Task* task = new Task();
        task->deserialize(ifs);
        tasks.pushBack(task);
    }

    updateDashboard();
}

const MyString& IndividualUser::getUserType() const {
    static MyString type = "IndividualUser";
    return type;
}

void IndividualUser::loadTasks() {
    std::ifstream inFile((username + "tasks.dat").c_str(), std::ios::binary);
    if (!inFile) return;

    size_t tasksCount;
    inFile.read(reinterpret_cast<char*>(&tasksCount), sizeof(tasksCount));
    tasks.clear();

    for (size_t i = 0; i < tasksCount; i++) 
    {
        Polymorphic_Ptr<Task> task = Task::deserialize(inFile);
        tasks.pushBack(task);
    }

    inFile.close();
}