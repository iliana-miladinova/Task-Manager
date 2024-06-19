#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "Task.h"
#include "PolymorphicPtr.hpp"
#include "Dashboard.h"

class IndividualUser : public User 
{
private:
    Vector<Polymorphic_Ptr<Task>> tasks; // Вектор от указатели към задачи
    Dashboard dashboard;
public:
    IndividualUser() = default;
    IndividualUser(const MyString& username, const MyString& password);

    void addTask(Polymorphic_Ptr<Task> task);
    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;

    const Vector<Polymorphic_Ptr<Task>>& getDashboardTasks() const;
    void updateDashboard();
    void login();

    void serializeUser(std::ofstream& ofs) const override;
    void deserializeUser(std::ifstream& ifs) override;

    const MyString& getUserType() const override;

    void removeTaskFromDashboard(int taskId);

    void loadTasks();
    void saveTasks() const;
};
