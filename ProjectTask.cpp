#include "ProjectTask.h"

ProjectTask::ProjectTask(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description, const MyString& assignee) :Task(id, name, dueDate, status, description), assignee(assignee)
{

}

void ProjectTask::serialize(std::ofstream& ofs) const
{
    /*Task::serialize(ofs);

    size_t assigneeLen = assignee.getSize();
    ofs.write((const char*)&assigneeLen, sizeof(assigneeLen));
    ofs.write(assignee.c_str(), assigneeLen);*/

    //Task::serialize(ofs);

    //// Сериализиране на специфичната част на ProjectTask
    //size_t assigneeLen = assignee.getSize();
    //ofs.write((const char*)&assigneeLen, sizeof(assigneeLen));
    //ofs.write(assignee.c_str(), assigneeLen);

    Task::serialize(ofs);
    size_t assigneeLength = assignee.getSize();
    ofs.write(reinterpret_cast<const char*>(&assigneeLength), sizeof(assigneeLength));
    ofs.write(assignee.c_str(), assigneeLength);
    /* ofs.write((const char*)&id, sizeof(id));

     size_t nameLen = name.getSize();
     ofs.write((const char*)&nameLen, sizeof(nameLen));
     ofs.write(name.c_str(), nameLen);

     size_t dueDateLen = dueDate.getSize();
     ofs.write((const char*)&dueDateLen, sizeof(dueDateLen));
     ofs.write(dueDate.c_str(), dueDateLen);

     ofs.write((const char*)&status, sizeof(status));

     size_t descriptionLen = description.getSize();
     ofs.write((const char*)&descriptionLen, sizeof(descriptionLen));
     ofs.write(description.c_str(), descriptionLen);

     size_t collaboratorsCount = collaborators.getSize();
     ofs.write((const char*)&collaboratorsCount, sizeof(collaboratorsCount));
     for (size_t i = 0; i <= collaboratorsCount; i++)
     {
         size_t collaboratorLen = collaborators[i].getSize();
         ofs.write((const char*)&collaboratorLen, sizeof(collaboratorLen));
         ofs.write(collaborators[i].c_str(), collaboratorLen);
     }*/

}

void ProjectTask::deserialize(std::ifstream& ifs)
{/*
    Task::deserialize(ifs);*/

    Task::deserialize(ifs);
    size_t assigneeLength;
    ifs.read(reinterpret_cast<char*>(&assigneeLength), sizeof(assigneeLength));
    char* assigneeBuffer = new char[assigneeLength + 1];
    ifs.read(assigneeBuffer, assigneeLength);
    assigneeBuffer[assigneeLength] = '\0';
    assignee = MyString(assigneeBuffer);
    delete[] assigneeBuffer;

    /*size_t assigneeLen;
    ifs.read((char*)&assigneeLen, sizeof(assigneeLen));
    char* assigneeBuffer = new char[assigneeLen + 1];
    ifs.read(assigneeBuffer, assigneeLen);
    assigneeBuffer[assigneeLen] = '\0';
    assignee = MyString(assigneeBuffer);
    delete[] assigneeBuffer;*/

    //Task baseTask = Task::deserialize(ifs);
    //this->name = baseTask.getName();
    //this->dueDate = baseTask.getDueDate();
    //this->description = baseTask.getDescription();
    ///*this->completed = baseTask.isCompleted();*/

    // Десериализиране на специфичната част на ProjectTask
    /*size_t assigneeLen;
    ifs.read((char*)&assigneeLen, sizeof(assigneeLen));
    char* assigneeBuffer = new char[assigneeLen + 1];
    ifs.read(assigneeBuffer, assigneeLen);
    assigneeBuffer[assigneeLen] = '\0';
    assignee = MyString(assigneeBuffer);
    delete[] assigneeBuffer;*/
    ////Task::deserialize(ifs);  // Десериализиране на базовите атрибути
    //ifs.read((char*)&id, sizeof(id));

    //size_t nameLen;
    //ifs.read((char*)&nameLen, sizeof(nameLen));
    //char* nameBuffer = new char[nameLen + 1];
    //ifs.read(nameBuffer, nameLen);
    //nameBuffer[nameLen] = '\0';
    //name = MyString(nameBuffer);
    //delete[] nameBuffer;

    //size_t dueDateLen;
    //ifs.read((char*)&dueDateLen, sizeof(dueDateLen));
    //char* dueDateBuffer = new char[dueDateLen + 1];
    //ifs.read(dueDateBuffer, dueDateLen);
    //dueDateBuffer[dueDateLen] = '\0';
    //dueDate = MyString(dueDateBuffer);
    //delete[] dueDateBuffer;

    //ifs.read((char*)&status, sizeof(status));

    //size_t descriptionLen;
    //ifs.read((char*)&descriptionLen, sizeof(descriptionLen));
    //char* descriptionBuffer = new char[descriptionLen + 1];
    //ifs.read(descriptionBuffer, descriptionLen);
    //descriptionBuffer[descriptionLen] = '\0';
    //description = MyString(descriptionBuffer);
    //delete[] descriptionBuffer;

    //size_t collaboratorsCount;
    //ifs.read((char*)&collaboratorsCount, sizeof(collaboratorsCount));
    //collaborators.clear();
    //for (size_t i = 0; i < collaboratorsCount; ++i)
    //{
    //    size_t collaboratorLen;
    //    ifs.read((char*)&collaboratorLen, sizeof(collaboratorLen));
    //    char* collaboratorBuffer = new char[collaboratorLen + 1];
    //    ifs.read(collaboratorBuffer, collaboratorLen);
    //    collaboratorBuffer[collaboratorLen] = '\0';
    //    collaborators.pushBack(MyString(collaboratorBuffer));
    //    delete[] collaboratorBuffer;
    //}
}

void ProjectTask::showTask() const
{
    Task::showTask();
    std::cout << "Assignee: " << assignee << std::endl;
    //std::cout << "Project Task\n";
    //// Показване на детайлите за задачата, включително и колабораторите
    //for (size_t i = 0; i < collaborators.getSize(); i++)
    //{

    //}
}

Task* ProjectTask::clone() const
{
    return new ProjectTask(*this);
}

const MyString& ProjectTask::getType() const
{
    static MyString type = "ProjectTask";
    return type;
}