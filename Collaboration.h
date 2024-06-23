#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "ProjectTask.h"
#include "User.h"
class Collaboration
{
private:
    int id;
    MyString name;
    MyString creator;
    Vector<MyString> participants;
    Vector<ProjectTask> tasks;

public:
    Collaboration() = default;
    Collaboration(int id, const MyString& name, const MyString& creator);

    int getId() const;
    const MyString& getName() const;
    const MyString& getCreator() const;
    const Vector<MyString>& getParticipants() const;
    const Vector<ProjectTask>& getTasks() const;

    void addParticipant(const MyString& username);
    void assignTask(const MyString& assignee, const MyString& name, const Optional<MyString>& dueDate, const MyString& description);

    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);

    void listTasks() const;
    void showCollaboration() const;
    bool isParticipant(const MyString& username) const;
};