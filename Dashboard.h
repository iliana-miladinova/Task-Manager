#pragma once

#include "MyVector.hpp"
#include "Task.h"
#include "PolymorphicPtr.hpp"
#include <fstream>
#include "HelperFunctions.h"

class Dashboard {
private:
    Vector<Polymorphic_Ptr<Task>> tasks;
    MyString filename;

public:
    Dashboard() = default;
    Dashboard(const MyString& userFile);

    void addTask(Polymorphic_Ptr<Task> task);
    void removeTask(int taskId);
    void update(const Vector<Polymorphic_Ptr<Task>>& allTasks);

    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;

    void saveToFile() const;
    void loadFromFile();
   /* void load(const MyString& username);
    void save(const MyString& username) const;*/
};