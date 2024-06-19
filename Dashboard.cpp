#include "Dashboard.h"

Dashboard::Dashboard(const MyString& userFile) : filename(userFile + "Dashboard.dat") 
{

}

void Dashboard::addTask(Polymorphic_Ptr<Task> task) {
    tasks.pushBack(task);
    saveToFile();
}

void Dashboard::removeTask(int taskId) {
    for (size_t i = 0; i < tasks.getSize(); ++i) {
        if (tasks[i]->getId() == taskId) {
            tasks.erase(i);
            saveToFile();
            break;
        }
    }
}

void Dashboard::update(const Vector<Polymorphic_Ptr<Task>>& allTasks) {
    tasks.clear();
    for (size_t i = 0; i < allTasks.getSize(); ++i) {
        std::tm dueDate = allTasks[i]->getDueDateFromString();
        if (HelperFunctions::isDueToday(dueDate) && allTasks[i]->getStatus() != Status::DONE) {
            tasks.pushBack(allTasks[i]);
        }
    }
    saveToFile();
}

const Vector<Polymorphic_Ptr<Task>>& Dashboard::getTasks() const {
    return tasks;
}

void Dashboard::saveToFile() const {
    std::ofstream ofs(filename.c_str(), std::ios::binary);
    if (ofs) {
        size_t tasksCount = tasks.getSize();
        ofs.write((const char*)&tasksCount, sizeof(tasksCount));
        for (size_t i = 0; i < tasksCount; ++i) {
            tasks[i]->serialize(ofs);
        }
    }
}

void Dashboard::loadFromFile() {
    std::ifstream ifs(filename.c_str(), std::ios::binary);
    if (ifs) {
        size_t tasksCount;
        ifs.read((char*)&tasksCount, sizeof(tasksCount));
        tasks.clear();
        for (size_t i = 0; i < tasksCount; ++i) {
            Task* task = new Task();
            task->deserialize(ifs);
            tasks.pushBack(task);
        }
    }
}