#include "Collaboration.h"
#include <iostream>

Collaboration::Collaboration(int id, const MyString& name, const MyString& creator): id(id), name(name), creator(creator) 
{

}

int Collaboration::getId() const 
{
    return id;
}

const MyString& Collaboration::getName() const 
{
    return name;
}

const MyString& Collaboration::getCreator() const
{
    return creator;
}

const Vector<MyString>& Collaboration::getParticipants() const
{
    return participants;
}

const Vector<ProjectTask>& Collaboration::getTasks() const 
{
    return tasks;
}

void Collaboration::addParticipant(const MyString& username) 
{
    participants.pushBack(username);
}

void Collaboration::assignTask(const MyString& assignee, const MyString& name, const Optional<MyString>& dueDate, const MyString& description) 
{
    int taskId = tasks.getSize() + 1;
    tasks.pushBack(ProjectTask(taskId, name, dueDate, Status::ON_HOLD, description, assignee));
}

void Collaboration::serialize(std::ofstream& ofs) const
{
    ofs.write((const char*)&id, sizeof(id));
    size_t length = name.getSize();
    ofs.write((const char*)&length, sizeof(length));
    ofs.write(name.c_str(), length);

    length = creator.getSize();
    ofs.write((const char*)&length, sizeof(length));
    ofs.write(creator.c_str(), length);

    size_t participantCount = participants.getSize();
    ofs.write((const char*)&participantCount, sizeof(participantCount));
    for (size_t i = 0; i < participantCount; i++)
    {
        length = participants[i].getSize();
        ofs.write((const char*)&length, sizeof(length));
        ofs.write(participants[i].c_str(), length);
    }

    size_t taskCount = tasks.getSize();
    ofs.write((const char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++) 
    {
        tasks[i].serialize(ofs);
    }
}

void Collaboration::deserialize(std::ifstream& ifs) 
{
    ifs.read((char*)&id, sizeof(id));

    size_t length;
    ifs.read((char*)&length, sizeof(length));
    char* buffer = new char[length + 1];
    ifs.read(buffer, length);
    buffer[length] = '\0';
    name = MyString(buffer);
    delete[] buffer;

    ifs.read((char*)&length, sizeof(length));
    buffer = new char[length + 1];
    ifs.read(buffer, length);
    buffer[length] = '\0';
    creator = MyString(buffer);
    delete[] buffer;

    size_t participantCount;
    ifs.read((char*)&participantCount, sizeof(participantCount));
    for (size_t i = 0; i < participantCount; i++)
    {
        ifs.read((char*)&length, sizeof(length));
        buffer = new char[length + 1];
        ifs.read(buffer, length);
        buffer[length] = '\0';
        participants.pushBack(MyString(buffer));
        delete[] buffer;
    }

    size_t taskCount;
    ifs.read((char*)&taskCount, sizeof(taskCount));
    for (size_t i = 0; i < taskCount; i++)
    {
        ProjectTask task;
        task.deserialize(ifs);
        tasks.pushBack(task);
    }
}

void Collaboration::listTasks() const 
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        tasks[i].showTask();
    }
}

void Collaboration::showCollaboration() const 
{
    std::cout << "Collaboration ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Creator: " << creator << std::endl;
    std::cout << "Participants: ";
    for (size_t i = 0; i < participants.getSize(); i++) 
    {
        std::cout << participants[i] << " ";
    }
    std::cout << std::endl;
    listTasks();
}

bool Collaboration::isParticipant(const MyString& username) const
{
    for (size_t i = 0; i < participants.getSize(); i++) 
    {
        if (participants[i] == username) 
        {
            return true;
        }
    }
    return false;
}