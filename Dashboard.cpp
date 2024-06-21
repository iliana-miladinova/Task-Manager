#include "Dashboard.h"

void Dashboard::addTask(Polymorphic_Ptr<Task> task) {
    tasks.pushBack(task);
}

void Dashboard::addTaskById(int id)
{
    /*for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId()==id && )
        {
            tasks.insert(tasks[i], i);
        }
    }*/

    if (tasks[id]->getStatus()!=Status::OVERDUE)
    {
        tasks.insert(tasks[id], id);
    }
}

void Dashboard::removeTask(int taskId) {
    for (size_t i = 0; i < tasks.getSize(); ++i) {
        if (tasks[i]->getId() == taskId) {
            tasks.erase(i);
            break;
        }
    }
}

const Vector<Polymorphic_Ptr<Task>>& Dashboard::getTasks() const {
    return tasks;
}

void Dashboard::serialize(std::ofstream& ofs) const {
    /*size_t taskCount = tasks.getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        tasks[i]->serialize(ofs);
    }*/

    size_t taskCount = tasks.getSize();
    ofs.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        tasks[i]->serialize(ofs);
    }
}

void Dashboard::deserialize(std::ifstream& ifs) {
    /*size_t taskCount;*/
   /* ifs.read((char*)&taskCount, sizeof(taskCount));
    tasks.clear();
    for (size_t i = 0; i < taskCount; ++i) {
        MyString taskType;
        taskType.deserialize(ifs);

        Polymorphic_Ptr<Task> task;
        if (taskType == "Task") {
            task.reset(new Task());
        }
        else if (taskType == "ProjectTask") {
            task.reset(new ProjectTask());
        }
        task->deserialize(ifs);
        tasks.pushBack(task);
    }*/

    size_t taskCount;
    ifs.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));
    for (size_t i = 0; i < taskCount; ++i) {
        Polymorphic_Ptr<Task> task;
        ifs.peek();
        if (ifs.eof()) break;
        ifs.peek();
        char type;
        ifs.read(&type, 1);
        if (type == 'P') {
            task = Polymorphic_Ptr<Task>(new ProjectTask());
        }
        else {
            task = Polymorphic_Ptr<Task>(new Task());
        }
        task->deserialize(ifs);
        tasks.pushBack(std::move(task));
    }
   /* size_t taskCount;
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
    }*/
}

void Dashboard::update(const Vector<Polymorphic_Ptr<Task>>& allTasks) {
    tasks.clear();
    for (size_t i = 0; i < allTasks.getSize(); ++i) {
        std::tm dueDate = allTasks[i]->getDueDateFromString();
        if (HelperFunctions::isDueToday(dueDate) && allTasks[i]->getStatus() != Status::DONE) {
            tasks.pushBack(allTasks[i]);
        }
    }
    /*saveToFile();*/
}

void Dashboard::saveToFile(const MyString& filename) const {
    /*std::ofstream ofs(filename.c_str(), std::ios::binary);
    if (ofs) {
        size_t tasksCount = tasks.getSize();
        ofs.write((const char*)&tasksCount, sizeof(tasksCount));
        for (size_t i = 0; i < tasksCount; ++i) {
            tasks[i]->serialize(ofs);
        }
    }*/

    std::ofstream ofs(filename.c_str(), std::ios::binary);
    serialize(ofs);
    ofs.close();
}

void Dashboard::loadFromFile(const MyString& filename) {
    /*std::ifstream ifs(filename.c_str(), std::ios::binary);
    if (ifs) {
        size_t tasksCount;
        ifs.read((char*)&tasksCount, sizeof(tasksCount));
        tasks.clear();
        for (size_t i = 0; i < tasksCount; ++i) {
            Task* task = new Task();
            task->deserialize(ifs);
            tasks.pushBack(task);
        }
    }*/

    std::ifstream ifs(filename.c_str(), std::ios::binary);
    if (ifs) {
        deserialize(ifs);
        ifs.close();
    }
}

void Dashboard::showTask() const
{
    if (tasks.isEmpty())
    {
        throw std::runtime_error("Dashboard is empty");
    }

    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        tasks[i]->showTask();
    }
}