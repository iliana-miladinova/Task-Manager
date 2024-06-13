#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "HelperFunctions.h"
#include <fstream>
#include "User.h"

//class Dashboard
//{
//private:
//	/*Vector<int> taskIds;*/
//	Vector<Task> tasks;
//	void saveToFile(const MyString& filename) const;
//	void loadFromFile(const MyString& filename);
//public:
//	void addTaskToDashboard(/*int id*/const Task& task);
//	void removeTaskFromDashboard(int id);
//	void showDashboard(const Vector<Task>& tasks) const;
//	void updateOnLogIn(const Vector<Task>& tasks, const MyString& filename);
//};

//class Dashboard 
//{
//private:
//    User user;
//    Vector<Task> tasks;
//
//
//    void loadTasks() 
//    {
//        std::ifstream inFile("tasks.txt");
//        if (!inFile) return;
//
//        int id;
//        MyString name;
//        MyString due_date;
//        MyString description;
//        Status status;
//        ////while (true/*inFile >> id >> name >> due_date >> status*/) {
//        ////    inFile.ignore(); // Ignore newline character
//        ////    std::getline(inFile, description.c_str());
//        ////    tasks.pushBack(Task(id, name, due_date, status, description));
//        ////}
//        ////inFile.close();
//
//        //while (inFile >> id) {
//        //    inFile.ignore(); // Ignore newline character before reading the name
//        //    std::getline(inFile, name.c_str());
//
//        //    std::getline(inFile, due_date.c_str());
//
//        //    int status_value;
//        //    inFile >> status_value;
//        //    status = static_cast<Status>(status_value);
//
//        //    inFile.ignore(); // Ignore newline character before reading the description
//        //    std::getline(inFile, description.c_str());
//
//        //    tasks.pushBack(Task(id, name, due_date, status, description));
//        //}
//        //inFile.close();
//        while (inFile >> id)
//        {
//            inFile.ignore(); // Ignore newline character before reading the name
//
//            char buffer[256];
//
//            inFile.getline(buffer, 256);
//            name = buffer;
//
//            inFile.getline(buffer, 256);
//            due_date = buffer;
//
//            int status_value;
//            inFile >> status_value;
//            status = static_cast<Status>(status_value);
//
//            inFile.ignore(); // Ignore newline character before reading the description
//            inFile.getline(buffer, 256);
//            description = buffer;
//
//            tasks.pushBack(Task(id, name, due_date, status, description));
//        }
//        inFile.close();
//    }
//
//    void saveTasks() {
//
//        std::ofstream outFile(/*user.username + */"tasks.txt");
//        for (size_t i = 0; i < tasks.getSize(); i++) 
//        {
//            outFile << tasks[i].getId() << " "
//                << tasks[i].getName() << " "
//                << tasks[i].getDueDate() << " "
//                << tasks[i].getStringFromStatus() << "\n"
//                << tasks[i].getDescription()<< "\n";
//        }
//        outFile.close();
//    }
//
//public:
//    Dashboard(User user) : user(user)
//    {
//        loadTasks();
//    }
//
//    ~Dashboard()
//    {
//        saveTasks();
//    }
//
//    void addTask(const Task& task) 
//    {
//        for (size_t i = 0; i < tasks.getSize(); i++)
//        {
//            if (tasks[i].getDueDate() == task.getDueDate() && tasks[i].getName() == task.getName()) 
//            {
//                std::cout << "Задача с това име и срок вече съществува.\n";
//                return;
//            }
//        }
//        tasks.pushBack(task);
//    }
//
//    void removeTask(int id) 
//    {
//        for (size_t i = 0; i < tasks.getSize(); ++i)
//        {
//            if (tasks[i].getId() == id) {
//                tasks.erase(i);
//                return;
//            }
//        }
//    }
//
//    void updateDashboard() {
//        /*std::string*/std::tm current_date = HelperFunctions::getCurrentDate();
//
//        // Премахване на изтекли задачи
//        for (size_t i = 0; i < tasks.getSize(); i++) 
//        {
//            if (HelperFunctions::isDate1LessThanDate2(tasks[i].getDueDateFromString(), current_date )/*|| tasks[i].status != "DONE"*/ || tasks[i].getStatus() == Status::DONE)
//            {
//                tasks.erase(i);
//                i--; // Намалява индекса след изтриване, за да не пропусне задача
//            }
//        }
//
//        // Добавяне на задачи за днешния ден
//        for (size_t i = 0; i < tasks.getSize(); i++) 
//        {
//            if (HelperFunctions::compareDates(tasks[i].getDueDateFromString() , current_date) && tasks[i].getStatus() ==Status::ON_HOLD) 
//            {
//                tasks[i].setStatus(Status::IN_PROCESS);
//            }
//        }
//    }
//
//    void showTasks() 
//    {
//        for (size_t i = 0; i < tasks.getSize(); i++) 
//        {
//            /*std::cout << "ID: " << tasks[i]
//                << ", Име: " << tasks[i].name
//                << ", Срок: " << tasks[i].due_date
//                << ", Статус: " << tasks[i].status
//                << ", Описание: " << tasks[i].description << "\n";*/
//            tasks[i].showTask();
//        }
//    }
//};
//
class Dashboard
{
private:
    User user;
    Vector<Task> tasks;

    void loadTasks()
    {
        std::ifstream inFile("task.txt");
        if (!inFile) return;

        int id;
        MyString name;
        MyString due_date;
        MyString description;
        Status status;

        while (inFile >> id)
        {
            inFile.ignore(); // Ignore newline character before reading the name

            char buffer[256];

            inFile.getline(buffer, 256);
            name = buffer;

            inFile.getline(buffer, 256);
            due_date = buffer;

            int status_value;
            inFile >> status_value;
            status = static_cast<Status>(status_value);

            inFile.ignore(); // Ignore newline character before reading the description
            inFile.getline(buffer, 256);
            description = buffer;

            tasks.pushBack(Task(id, name, due_date, status, description));
        }
        inFile.close();
    }

    void saveTasks()
    {
        std::ofstream outFile("task.txt");
        for (size_t i = 0; i < tasks.getSize(); i++)
        {
            outFile << tasks[i].getId() << "\n"
                << tasks[i].getName() << "\n"
                << tasks[i].getDueDate() << "\n"
                << static_cast<int>(tasks[i].getStatus()) << "\n"
                << tasks[i].getDescription() << "\n";
        }
        outFile.close();
    }

public:
    Dashboard(User user) : user(user)
    {
        loadTasks();
    }

    ~Dashboard()
    {
        saveTasks();
    }

    void addTask(const Task& task)
    {
        for (size_t i = 0; i < tasks.getSize(); i++)
        {
            if (tasks[i].getDueDate() == task.getDueDate() && tasks[i].getName() == task.getName())
            {
                std::cout << "Задача с това име и срок вече съществува.\n";
                return;
            }
        }
        tasks.pushBack(task);
    }

    void removeTask(int id)
    {
        for (size_t i = 0; i < tasks.getSize(); ++i)
        {
            if (tasks[i].getId() == id) {
                tasks.erase(i);
                return;
            }
        }
    }

    void updateDashboard()
    {
        std::tm current_date = HelperFunctions::getCurrentDate();

        for (size_t i = 0; i < tasks.getSize(); i++)
        {
            if (HelperFunctions::isDate1LessThanDate2(tasks[i].getDueDateFromString(), current_date) || tasks[i].getStatus() == Status::DONE)
            {
                tasks.erase(i);
                i--; // Намалява индекса след изтриване, за да не пропусне задача
            }
        }

        for (size_t i = 0; i < tasks.getSize(); i++)
        {
            if (HelperFunctions::compareDates(tasks[i].getDueDateFromString(), current_date) && tasks[i].getStatus() == Status::ON_HOLD)
            {
                tasks[i].setStatus(Status::IN_PROCESS);
            }
        }
    }

    void showTasks()
    {
        for (size_t i = 0; i < tasks.getSize(); i++)
        {
            tasks[i].showTask();
        }
    }
};