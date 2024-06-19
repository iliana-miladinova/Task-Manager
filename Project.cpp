// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IndividualUser.h"
#include "Task.h"
#include "PolymorphicPtr.hpp"

int main()
{
    IndividualUser individualUser("john_doe", "securepassword");

    // Create tasks and add them to the user
    MyString taskName1("Complete Report");
    MyString dueDate1("18-06-2024");
    MyString description1("Finish the annual report by June 18th.");
    Polymorphic_Ptr<Task> task1(new Task(1, taskName1, dueDate1, Status::IN_PROCESS, description1));

    MyString taskName2("Meeting Preparation");
    MyString dueDate2("19-06-2024");
    MyString description2("Prepare slides for the meeting.");
    Polymorphic_Ptr<Task> task2(new Task(2, taskName2, dueDate2, Status::IN_PROCESS, description2));

    individualUser.addTask(task1);
    individualUser.addTask(task2);

    // Simulate user login to load and update the dashboard
    individualUser.login();

    // Show all tasks
    std::cout << "All Tasks:\n";
    const Vector<Polymorphic_Ptr<Task>>& allTasks = individualUser.getTasks();
    for (size_t i = 0; i < allTasks.getSize(); ++i) {
        allTasks[i]->showTask();
    }

    // Show dashboard tasks
    std::cout << "\nDashboard Tasks for Today:\n";
    const Vector<Polymorphic_Ptr<Task>>& dashboardTasks = individualUser.getDashboardTasks();
    for (size_t i = 0; i < dashboardTasks.getSize(); ++i) {
        dashboardTasks[i]->showTask();
    }

    // Remove a task from the dashboard and show the updated dashboard
    individualUser.removeTaskFromDashboard(1);

    std::cout << "\nUpdated Dashboard Tasks for Today after removing task with ID 1:\n";
    const Vector<Polymorphic_Ptr<Task>>& updatedDashboardTasks = individualUser.getDashboardTasks();
    for (size_t i = 0; i < updatedDashboardTasks.getSize(); ++i) {
        updatedDashboardTasks[i]->showTask();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
