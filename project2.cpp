
// project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "UserManager.h"
//#include "User.h"
//#include "Task.h"
//#include "ProjectTask.h"
//#include "PolymorphicPtr.hpp"
//#include "Dashboard.h"
//
//int main() {
//    UserManager userManager;
//    // Регистрация на нов потребител
//    userManager.registerUser("user1", "password1");
//    userManager.registerUser("user2", "password2");
//
//    // Запазване на потребителите във файл
//    userManager.saveUsers();
//    std::cout << "Users saved successfully!" << std::endl;
//
//    // Зареждане на потребителите от файл
//    userManager.loadUsers();
//    std::cout << "Users loaded successfully!" << std::endl;
//
//    // Опит за вход
//    User* user = userManager.loginUser("user1", "password1");
//    if (user) {
//        std::cout << "Login successful for user: " << user->getUsername() << std::endl;
//    }
//    else {
//        std::cout << "Login failed!" << std::endl;
//    }
//
//    return 0;
//    MyString username("user1");
//    MyString password("pass123");
//    User user(username, password);
//
//     Добавяне на задачи
//    Polymorphic_Ptr<Task> task1(new Task(1, "Task 1", "20-06-2024", Status::IN_PROCESS, "Description 1"));
//    Polymorphic_Ptr<Task> task2(new ProjectTask(2, "Project Task 1", "21-06-2024", Status::ON_HOLD, "Description 2", "Assignee 1"));
//    Polymorphic_Ptr<Task> task3(new Task(3, "Task 3", "22-06-2024", Status::DONE, "Description 3"));
//
//    user.addTask(task1);
//    user.addTask(task2);
//    user.addTask(task3);
//
//     Запазване на потребителя и неговите задачи във файл
//    std::ofstream ofs("user_data.dat", std::ios::binary);
//    if (ofs) {
//        user.serializeUser(ofs);
//        ofs.close();
//        std::cout << "User data serialized successfully!" << std::endl;
//    }
//    else {
//        std::cerr << "Failed to open file for serialization!" << std::endl;
//        return 1;
//    }
//
//     Зареждане на потребителя и неговите задачи от файл
//    User loadedUser;
//    std::ifstream ifs("user_data.dat", std::ios::binary);
//    if (ifs) {
//        loadedUser.deserializeUser(ifs);
//        ifs.close();
//        std::cout << "User data deserialized successfully!" << std::endl;
//    }
//    else {
//        std::cerr << "Failed to open file for deserialization!" << std::endl;
//        return 1;
//    }
//
//     Визуализация на Dashboard
//    /*Dashboard::showUserTasks(loadedUser);*/
//}



//#include <iostream>
//#include <stdexcept>
//#include "UserManager.h" // Assuming UserManager class is defined in UserManager.h
//#include "MyString.h"
//
//void printHelp() {
//    std::cout << "Available commands:\n";
//    std::cout << "  register <username> <password>\n";
//    std::cout << "  login <username> <password>\n";
//    std::cout << "  logout\n";
//    std::cout << "  add-task <task_name> <due_date> <description>\n";
//    std::cout << "  get-task <task_id_or_name>\n";
//    std::cout << "  update-task-name <task_id> <new_name>\n";
//    std::cout << "  start-task <task_id>\n";
//    std::cout << "  finish-task <task_id>\n";
//    std::cout << "  delete-task <task_id>\n";
//    std::cout << "  list-tasks [<due_date>]\n";
//    std::cout << "  add-collaboration <collaboration_name>\n";
//    std::cout << "  add-user <collaboration_name> <username>\n";
//    std::cout << "  assign-task <collaboration_name> <username> <task_name> <due_date> <description>\n";
//    std::cout << "  list-collaborations\n";
//    std::cout << "  list-tasks <collaboration_name>\n";
//    std::cout << "  add-task-to-dashboard <task_id>\n";
//    std::cout << "  list-dashboard\n";
//    std::cout << "  exit\n";
//}
//
//void processCommand(UserManager& userManager, const std::string& command) {
//    std::istringstream iss(command);
//    std::string cmd;
//    iss >> cmd;
//
//    try {
//        if (cmd == "register") {
//            MyString username, password;
//            iss >> username >> password;
//            userManager.registerUser(username, password);
//            std::cout << "Registered successfully!\n";
//            if (cmd == "add-task")
//            {
//                MyString name, dueDate;
//                iss >> name >> dueDate;
//
//                std::string descriptionStr;
//                std::getline(iss >> std::ws, descriptionStr);  // std::ws to discard any leading whitespace
//
//                MyString description(descriptionStr.c_str());
//
//                userManager.addTask(name, dueDate, description);
//                std::cout << "Task added successfully!\n";
//            }
//        }
//        else if (cmd == "login") {
//           MyString username, password;
//            iss >> username >> password;
//            userManager.loginUser(username, password);
//            std::cout << "Welcome back, " << username << "!\n";
//        }
//        else if (cmd == "logout") {
//            userManager.logoutUser();
//            std::cout << "Logged out successfully!\n";
//        }
//        else if (cmd == "add-task") {
//           ///* MyString name, dueDate, description;
//           // iss >> name >> dueDate >> std::ws;
//           // std::getline(iss, description);
//           // userManager.addTaskToDashboard(name, dueDate, description);
//           // std::cout << "Task added successfully!\n";*/
//            //MyString name, dueDate, description;
//            //iss >> name >> dueDate;
//
//            //// Read description manually until newline
//            //MyString descTemp;
//            //char c;
//            //iss >> c;  // Read the first character after dueDate
//            //while (c != '\n') {
//            //    descTemp += MyString(&c, 1); // Append single character to descTemp
//            //    iss >> c;
//            //}
//            //description = descTemp;
//
//            //userManager.addTaskToDashboard(name, dueDate, description);
//            //std::cout << "Task added successfully!\n";
//            //MyString name, dueDate, description;
//            //iss >> name >> dueDate;
//
//            //// Read description manually until newline
//            //MyString descTemp;
//            //char c;
//            //iss >> c;  // Read the first character after dueDate
//            //while (c != '\n') {
//            //    descTemp = descTemp + MyString(&c); // Concatenate single character to descTemp
//            //    iss >> c;
//            //}
//            //description = descTemp;
//          /*  int id;
//            iss >> id;
//
//            userManager.addTaskToDashboard(id);
//            std::cout << "Task added successfully!\n";
//            */
//        }
//        else if (cmd == "get-task") {
//            MyString taskIdentifier;
//            iss >> taskIdentifier;
//            userManager.getTask(taskIdentifier);
//        }
//        else if (cmd == "update-task-name") {
//            int taskId;
//           MyString newName;
//            iss >> taskId >> newName;
//            userManager.updateTaskName(taskId, newName);
//            std::cout << "Task name updated successfully!\n";
//        }
//        else if (cmd == "start-task") {
//            int taskId;
//            iss >> taskId;
//            userManager.startTask(taskId);
//            std::cout << "Task started successfully!\n";
//        }
//      /*  else if (cmd == "finish-task") {
//            int taskId;
//            iss >> taskId;
//            userManager.finishTask(taskId);
//            std::cout << "Congratulations on completing the task!\n";
//        }*/
//        else if (cmd == "delete-task") {
//            int taskId;
//            iss >> taskId;
//            userManager.deleteTask(taskId);
//            std::cout << "Task deleted successfully!\n";
//        }
//        else if (cmd == "list-tasks") {
//            MyString param;
//            iss >> param;
//            userManager.listTasks(param);
//        }
//       /* else if (cmd == "add-collaboration") {
//            std::string collabName;
//            iss >> collabName;
//            userManager.addCollaboration(collabName);
//            std::cout << "Collaboration added successfully!\n";
//        }*/
//       /* else if (cmd == "add-user") {
//            std::string collabName, username;
//            iss >> collabName >> username;
//            userManager.addUserToCollaboration(collabName, username);
//            std::cout << "User added successfully to collaboration!\n";
//        }*/
//        /*else if (cmd == "assign-task") {
//            std::string collabName, username, taskName, dueDate, description;
//            iss >> collabName >> username >> taskName >> dueDate >> std::ws;
//            std::getline(iss, description);
//            userManager.assignTaskToUser(collabName, username, taskName, dueDate, description);
//            std::cout << "Task assigned successfully to user!\n";
//        }
//        else if (cmd == "list-collaborations") {
//            userManager.listCollaborations();
//        }
//        else if (cmd == "list-dashboard") {
//            userManager.listDashboard();
//        }*/
//        else if (cmd == "add-task-to-dashboard") {
//            int taskId;
//            iss >> taskId;
//            userManager.addTaskToDashboard(taskId);
//            std::cout << "Task added to dashboard successfully!\n";
//        }
//        else if (cmd == "exit") {
//            std::cout << "Exited successfully!\n";
//            exit(0); // Exit the program
//        }
//        else {
//            std::cout << "Unknown command. Type 'help' for list of commands.\n";
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//}
//
//int main() {
//    UserManager userManager;
//
//    std::cout << "Welcome to Task Management System!\n";
//    std::cout << "Type 'help' for list of commands.\n";
//
//    std::string command;
//    while (true) {
//        std::cout << "> ";
//        std::getline(std::cin, command);
//
//        if (command == "help") {
//            printHelp();
//        }
//        else {
//            processCommand(userManager, command);
//        }
//    }
//
//    return 0;
//}
#include "UserManager.h"
#include <iostream>

//
//void printMenu() {
//    std::cout << "1. Register\n";
//    std::cout << "2. Login\n";
//    std::cout << "3. Add Task\n";
//    std::cout << "4. List Tasks\n";
//    std::cout << "5. Logout\n";
//    std::cout << "6. Exit\n";
//    std::cout << "Enter choice: ";
//}
//
//int main() {
//    UserManager userManager;
//    int choice;
//    MyString username, password, name, dueDate, description;
//
//    while (true) {
//        printMenu();
//        std::cin >> choice;
//        switch (choice) {
//        case 1:
//            std::cout << "Enter username: ";
//            std::cin >> username;
//            std::cout << "Enter password: ";
//            std::cin >> password;
//            userManager.registerUser(username, password);
//            break;
//        case 2:
//            std::cout << "Enter username: ";
//            std::cin >> username;
//            std::cout << "Enter password: ";
//            std::cin >> password;
//            userManager.loginUser(username, password);
//            break;
//        case 3:
//            if (userManager.getCurrentUser()) {
//                std::cout << "Enter task name: ";
//                std::cin >> name;
//                std::cout << "Enter due date (YYYY-MM-DD): ";
//                std::cin >> dueDate;
//                std::cout << "Enter description: ";
//                std::cin.ignore(); // Ignore the newline character left by std::cin
//                std::string desc;
//                std::getline(std::cin, desc);
//                description = desc.c_str(); // Convert std::string to MyString
//                userManager.addTask(name, dueDate, description);
//            }
//            else {
//                std::cout << "Please login first.\n";
//            }
//            break;
//        case 4:
//            if (userManager.getCurrentUser()) {
//                userManager.listTasks();
//            }
//            else {
//                std::cout << "Please login first.\n";
//            }
//            break;
//        case 5:
//            userManager.logoutUser();
//            break;
//        case 6:
//            return 0;
//        default:
//            std::cout << "Invalid choice. Please try again.\n";
//        }
//    }
//    return 0;
//}
// 
//void printMenu() {
//    std::cout << "1. Register\n";
//    std::cout << "2. Login\n";
//    std::cout << "3. Add Task\n";
//    std::cout << "4. Update Task Name\n";
//    std::cout << "5. Start Task\n";
//    std::cout << "6. Update Task Description\n";
//    std::cout << "7. Remove Task From Dashboard\n";
//    std::cout << "8. Add Task To Dashboard\n";
//    std::cout << "9. Delete Task\n";
//    std::cout << "10. Get Task by Name\n";
//    std::cout << "11. Get Task by ID\n";
//    std::cout << "12. List Tasks\n";
//    std::cout << "13. List Tasks by Date\n";
//    std::cout << "14. List Completed Tasks\n";
//    std::cout << "15. List Dashboard\n";
//    std::cout << "16. Finish Task\n";
//    std::cout << "17. Logout\n";
//    std::cout << "18. Exit\n";
//    std::cout << "Enter choice: ";
//}
//
//void testUpdateTaskName(UserManager& userManager) {
//    MyString username = "testuser";
//    MyString password = "password";
//    MyString name = "TestTask";
//    MyString newName = "UpdatedTask";
//    MyString dueDate = "2024-06-30";
//    MyString description = "Test task description";
//
//    userManager.registerUser(username, password);
//    userManager.loginUser(username, password);
//
//    userManager.addTask(name, dueDate, description);
//    userManager.listTasks();
//
//    std::cout << "Updating task name...\n";
//    userManager.updateTaskName(1, newName);  // Assuming the task ID is 1
//    userManager.listTasks();
//
//    userManager.logoutUser();
//}
//
//int main() {
//    UserManager userManager;
//    int choice;
//
//    while (true) {
//        printMenu();
//        std::cin >> choice;
//        switch (choice) {
//        case 1:
//        {
//            MyString username, password;
//            std::cout << "Enter username: ";
//            std::cin >> username;
//            std::cout << "Enter password: ";
//            std::cin >> password;
//            userManager.registerUser(username, password);
//        }
//        break;
//        case 2:
//        {
//            MyString username, password;
//            std::cout << "Enter username: ";
//            std::cin >> username;
//            std::cout << "Enter password: ";
//            std::cin >> password;
//            userManager.loginUser(username, password);
//        }
//        break;
//        case 3:
//        {
//            if (userManager.getCurrentUser()) {
//                MyString name, dueDate, description;
//                std::cout << "Enter task name: ";
//                std::cin >> name;
//                std::cout << "Enter due date (YYYY-MM-DD): ";
//                std::cin >> dueDate;
//                std::cout << "Enter description: ";
//                std::cin.ignore(); // Ignore the newline character left by std::cin
//                std::string desc;
//                std::getline(std::cin, desc);
//                description = desc.c_str(); // Convert std::string to MyString
//                userManager.addTask(name, dueDate, description);
//            }
//            else {
//                std::cout << "Please login first.\n";
//            }
//        }
//        break;
//        case 4:
//        {
//            if (userManager.getCurrentUser()) {
//                int id;
//                MyString newName;
//                std::cout << "Enter task ID: ";
//                std::cin >> id;
//                std::cout << "Enter new task name: ";
//                std::cin >> newName;
//                userManager.updateTaskName(id, newName);
//            }
//            else {
//                std::cout << "Please login first.\n";
//            }
//        }
//        break;
//        case 12:
//        {
//            if (userManager.getCurrentUser()) {
//                userManager.listTasks();
//            }
//            else {
//                std::cout << "Please login first.\n";
//            }
//        }
//        break;
//        case 17:
//            userManager.logoutUser();
//            break;
//        case 18:
//            return 0;
//        default:
//            std::cout << "Invalid choice. Please try again.\n";
//        }
//    }
//
//    return 0;
//}
// 
#include <iostream>
#include <string>
#include "UserManager.h"

void printMenu() {
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Add Task\n";
    std::cout << "4. Update Task Name\n";
    std::cout << "12. List Tasks\n";
    std::cout << "17. Logout\n";
    std::cout << "18. Exit\n";
    std::cout << "Enter choice: ";
}

void testUpdateTaskName(UserManager& userManager) {
    MyString username = "testuser";
    MyString password = "password";
    MyString name = "TestTask";
    MyString newName = "UpdatedTask";
    MyString dueDate = "30-06-2024";
    MyString description = "Test task description";

    userManager.registerUser(username, password);
    userManager.loginUser(username, password);

    userManager.addTask(name, dueDate, description);
    userManager.listTasks();

    std::cout << "Updating task name...\n";
    userManager.updateTaskName(1, newName);  // Assuming the task ID is 1
    userManager.listTasks();

    userManager.logoutUser();
}

int main() {
    UserManager userManager;
    int choice;
   /* testUpdateTaskName(userManager);*/
    while (true) {
        printMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
        {
            MyString username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            userManager.registerUser(username, password);
        }
        break;
        case 2:
        {
            MyString username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            userManager.loginUser(username, password);
        }
        break;
        case 3:
        {
            if (userManager.getCurrentUser()) {
                MyString name, dueDate, description;
                std::cout << "Enter task name: ";
                std::cin >> name;
                std::cout << "Enter due date (YYYY-MM-DD): ";
                std::cin >> dueDate;
                std::cout << "Enter description: ";
                std::cin.ignore(); // Ignore the newline character left by std::cin
                std::string desc;
                std::getline(std::cin, desc);
                description = desc.c_str(); // Convert std::string to MyString
                userManager.addTask(name, dueDate, description);
            }
            else {
                std::cout << "Please login first.\n";
            }
        }
        break;
        case 4:
        {
            if (userManager.getCurrentUser()) {
                int id;
                MyString newName;
                std::cout << "Enter task ID: ";
                std::cin >> id;
                std::cout << "Enter new task name: ";
                std::cin >> newName;
                userManager.updateTaskName(id, newName);
            }
            else {
                std::cout << "Please login first.\n";
            }
        }
        break;
        case 12:
        {
            if (userManager.getCurrentUser()) {
                try {
                    userManager.listTasks();
                }
                catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Please login first.\n";
            }
        }
        break;
        case 17:
            userManager.logoutUser();
            break;
        case 18:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
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
