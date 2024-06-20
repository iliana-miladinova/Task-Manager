
// project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "Task.h"
#include "ProjectTask.h"
#include "PolymorphicPtr.hpp"
#include "Dashboard.h"

int main() {
    //UserManager userManager;
    //// Регистрация на нов потребител
    //userManager.registerUser("user1", "password1");
    //userManager.registerUser("user2", "password2");

    //// Запазване на потребителите във файл
    //userManager.saveUsers();
    //std::cout << "Users saved successfully!" << std::endl;

    //// Зареждане на потребителите от файл
    //userManager.loadUsers();
    //std::cout << "Users loaded successfully!" << std::endl;

    //// Опит за вход
    //User* user = userManager.loginUser("user1", "password1");
    //if (user) {
    //    std::cout << "Login successful for user: " << user->getUsername() << std::endl;
    //}
    //else {
    //    std::cout << "Login failed!" << std::endl;
    //}

    //return 0;
    MyString username("user1");
    MyString password("pass123");
    User user(username, password);

    // Добавяне на задачи
    Polymorphic_Ptr<Task> task1(new Task(1, "Task 1", "20-06-2024", Status::IN_PROCESS, "Description 1"));
    Polymorphic_Ptr<Task> task2(new ProjectTask(2, "Project Task 1", "21-06-2024", Status::ON_HOLD, "Description 2", "Assignee 1"));
    Polymorphic_Ptr<Task> task3(new Task(3, "Task 3", "22-06-2024", Status::DONE, "Description 3"));

    user.addTask(task1);
    user.addTask(task2);
    user.addTask(task3);

    // Запазване на потребителя и неговите задачи във файл
    std::ofstream ofs("user_data.dat", std::ios::binary);
    if (ofs) {
        user.serializeUser(ofs);
        ofs.close();
        std::cout << "User data serialized successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open file for serialization!" << std::endl;
        return 1;
    }

    // Зареждане на потребителя и неговите задачи от файл
    User loadedUser;
    std::ifstream ifs("user_data.dat", std::ios::binary);
    if (ifs) {
        loadedUser.deserializeUser(ifs);
        ifs.close();
        std::cout << "User data deserialized successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open file for deserialization!" << std::endl;
        return 1;
    }

    // Визуализация на Dashboard
    /*Dashboard::showUserTasks(loadedUser);*/
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
