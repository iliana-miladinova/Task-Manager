#include "ProjectTask.h"
ProjectTask::ProjectTask():Task() 
{

}
ProjectTask::ProjectTask(int id, const MyString& name, const Optional<MyString>& dueDate, const Status& status, const MyString& description, const MyString& assignee) :Task(id, name, dueDate, status, description), assignee(assignee)
{

}

void ProjectTask::serialize(std::ofstream& ofs) const
{
    Task::serialize(ofs);
    size_t assigneeLength = assignee.getSize();
    ofs.write((const char*)&assigneeLength, sizeof(assigneeLength));
    ofs.write(assignee.c_str(), assigneeLength);

}

void ProjectTask::deserialize(std::ifstream& ifs)
{

    Task::deserialize(ifs);
    size_t assigneeLength;
    ifs.read((char*)&assigneeLength, sizeof(assigneeLength));
    char* assigneeBuffer = new char[assigneeLength + 1];
    ifs.read(assigneeBuffer, assigneeLength);
    assigneeBuffer[assigneeLength] = '\0';
    assignee = MyString(assigneeBuffer);
    delete[] assigneeBuffer;

  
}

void ProjectTask::showTask() const
{
    Task::showTask();
    std::cout << "Assignee: " << assignee << std::endl;
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