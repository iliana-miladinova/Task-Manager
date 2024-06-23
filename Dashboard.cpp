#include "Dashboard.h"

void Dashboard::addTask(Polymorphic_Ptr<Task> task)
{
    tasks.pushBack(task);
}

void Dashboard::addTaskById(int id)
{
    if (tasks[id]->getStatus() != Status::OVERDUE)
    {
        tasks.insert(tasks[id], id);
    }
}

void Dashboard::removeTask(int taskId)
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i]->getId() == taskId) 
        {
            tasks.erase(i);
            break;
        }
    }
}

const Vector<Polymorphic_Ptr<Task>>& Dashboard::getTasks() const
{
    return tasks;
}

void Dashboard::serialize(std::ofstream& ofs) const
{

    size_t taskCount = tasks.getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++) 
    {
        char type;
        if (tasks[i]->getType() == "ProjectTask")
        {
            type = 'P';
        }
        else
        {
            type = 'T';
        }
        ofs.write(&type, sizeof(type));
        tasks[i]->serialize(ofs);
    }
}

void Dashboard::deserialize(std::ifstream& ifs) 
{

    size_t taskCount;
    ifs.read((char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++)
    {
        Polymorphic_Ptr<Task> task;
        char type;
        ifs.read(&type, sizeof(type));
        if (type == 'P')
        {
            task = Polymorphic_Ptr<Task>(new ProjectTask());
        }
        else 
        {
            task = Polymorphic_Ptr<Task>(new Task());
        }
        task->deserialize(ifs);
        tasks.pushBack(std::move(task));
    }
}

void Dashboard::update(const Vector<Polymorphic_Ptr<Task>>& allTasks)
{
    tasks.clear();
    for (size_t i = 0; i < allTasks.getSize(); i++) 
    {
        if (allTasks[i]->getDueDate().containsData()) 
        {
            std::tm dueDate = allTasks[i]->getDueDateFromString();
            if (HelperFunctions::isDueToday(dueDate) && allTasks[i]->getStatus() != Status::DONE) 
            {
                tasks.pushBack(allTasks[i]);
            }
        }
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