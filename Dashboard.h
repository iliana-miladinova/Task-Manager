#pragma once
#include "Task.h"
#include "PolymorphicPtr.hpp"
#include "MyVector.hpp"
#include <fstream>
#include "ProjectTask.h"
#include "HelperFunctions.h"

class Dashboard {
private:
    Vector<Polymorphic_Ptr<Task>> tasks; // Задачи в Dashboard-а

   /*???*/ MyString filename;

public:
    void addTask(Polymorphic_Ptr<Task> task);
    void removeTask(int taskId);
    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;

    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);

    void saveToFile() const;
    void loadFromFile();
    void update(const Vector<Polymorphic_Ptr<Task>>& allTasks);
};