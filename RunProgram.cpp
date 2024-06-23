#include "RunProgram.h"
#include <sstream>
#include "HelperFunctions.h"

void RunProgram::run() 
{
    MyString command;
    while (true) 
    {
        std::cout << "> ";
        HelperFunctions::myGetline(std::cin, command);
        if (command == "exit")
        {
            std::cout << "Exited successfully!" << std::endl;
            break;
        }
        try 
        {
            processCommand(command);
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void RunProgram::processCommand(const MyString& command)
{
    std::istringstream iss(command.c_str());
    MyString cmd;
    iss >> cmd;

    try
    {
        if (cmd == "register") 
        {
            MyString username, password;
            if (!(iss >> username >> password))
            {
                throw std::runtime_error("Error: Invalid syntax. Use: register <username> <password>");
                return;
            }
            registerUser(username, password);
        }
        else if (cmd == "login")
        {
            MyString username, password;
            if (!(iss >> username >> password)) 
            {
                throw std::runtime_error("Invalid syntax. Use: login <username> <password>");
            }
            loginUser(username, password);
        }
        else if (cmd == "add-task") {
            MyString name, dueDate, description;
            if (!(iss >> name >> dueDate))
            {
                throw std::runtime_error("Invalid syntax. Use: add-task <name> <due_date> <description>");
            }
            HelperFunctions::myGetline(iss, description);

            size_t start = 0;
            while (start < description.getSize() && HelperFunctions::isWhitespace(description[start])) 
            {
                start++;
            }
            size_t end = description.getSize();
            while (end > start && HelperFunctions::isWhitespace(description[end - 1])) {
                end--;
            }
            MyString trimmedDescrip;
            for (size_t i = start; i < end; i++) 
            {
                char tempStr[2] = {description[i], '\0'};
                trimmedDescrip += MyString(tempStr);
            }

            addTask(name, dueDate, trimmedDescrip);
        }
        else if (cmd == "get-task") 
        {
            MyString idn;
            if (!(iss >> idn))
            {
                throw std::runtime_error("Invalid syntax. Use: get-task <name> or get-task <id>");
            }
            getTask(idn);
        }
        else if (cmd == "update-task-name") 
        {
            int id;
            MyString name;
            if (!(iss >> id >> name)) 
            {
                throw std::runtime_error("Invalid syntax. Use: update-task-name <id> <name>");
            }
            updateTaskName(id, name);
        }
        else if (cmd == "start-task") 
        {
            int id;
            if (!(iss >> id))
            {
                throw std::runtime_error("Invalid syntax. Use: start-task <id>");
            }
            startTask(id);
        }
        else if (cmd == "update-task-description")
        {
            int id;
            MyString description;
            if (!(iss >> id))
            {
                throw std::runtime_error("Invalid syntax. Use: update-task-description <id> <description>");
            }
            HelperFunctions::myGetline(iss, description);

            size_t start = 0;
            while (start < description.getSize() && HelperFunctions::isWhitespace(description[start]))
            {
                start++;
            }

            size_t end = description.getSize();
            while (end > start && HelperFunctions::isWhitespace(description[end - 1]))
            {
                end--;
            }

            MyString trimmedDescrip;
            for (size_t i = start; i < end; i++)
            {
                char tempStr[2] = { description[i], '\0'};
                trimmedDescrip += MyString(tempStr);
            }

            updateTaskDescription(id, trimmedDescrip);
        }
        else if (cmd == "remove-task-from-dashboard")
        {
            int id;
            if (!(iss >> id)) 
            {
                throw std::runtime_error("Invalid syntax. Use: remove-task-from-dashboard <id>");
            }
            removeTaskFromDashboard(id);
        }
        else if (cmd == "add-task-to-dashboard") 
        {
            int id;
            if (!(iss >> id))
            {
                throw std::runtime_error("Invalid syntax. Use: add-task-to-dashboard <id>");
            }
            addTaskToDashboard(id);
        }
        else if (cmd == "delete-task")
        {
            int id;
            if (!(iss >> id))
            {
                throw std::runtime_error("Invalid syntax. Use: delete-task <id>");
            };
            deleteTask(id);
        }
        else if (cmd == "list-tasks") 
        {
            MyString date;
            if (iss >> date)
            {
                listTasks(date);
            }
            else 
            {
                listTasks();
            }
        }
        else if (cmd == "list-completed-tasks") 
        {
            listCompletedTasks();
        }
        else if (cmd == "list-dashboard")
        {
            listDashboard();
        }
        else if (cmd == "finish-task")
        {
            int id;
            if (!(iss >> id)) 
            {
                throw std::runtime_error("Invalid syntax. Use: finish-task <id>");
            }
            finishTask(id);
        }
        else if (cmd == "logout") 
        {
            logout();
        }
        else if (cmd == "add-collaboration") 
        {
            MyString name;
            if (!(iss >> name))
            {
                throw std::runtime_error("Invalid syntax. Use: add-collaboration <name>");
            }
            addCollaboration(name);
        }
        else if (cmd == "delete-collaboration")
        {
            MyString name;
            if (!(iss >> name))
            {
                throw std::runtime_error("Invalid syntax. Use: delete-collaboration <name>");
            }
            deleteCollaboration(name);
        }
        else if (cmd == "list-collaborations") 
        {
            listCollaborations();
        }
        else if (cmd == "add-user")
        {
            MyString collabName, username;
            if (!(iss >> collabName >> username))
            {
                throw std::runtime_error("Invalid syntax. Use: add-user <collaboration name> <username>");
            }
            addUserToCollaboration(collabName, username);
        }
        else if (cmd == "assign-task") {
            MyString collabName, username, taskName, dueDate, description;
            if (!(iss >> collabName >> username >> taskName >> dueDate)) 
            {
                throw std::runtime_error("Invalid syntax. Use: assign-task <collaboration name> <username> <name> <due_date> <description>");
            }
            HelperFunctions::myGetline(iss, description);

            size_t start = 0;
            while (start < description.getSize() && HelperFunctions::isWhitespace(description[start]))
            {
                start++;
            }

            size_t end = description.getSize();
            while (end > start && HelperFunctions::isWhitespace(description[end - 1])) 
            {
                end--;
            }

            MyString trimmedDescrip;
            for (size_t i = start; i < end; i++)
            {
                char tempStr[2] = { description[i], '\0' };
                trimmedDescrip += MyString(tempStr);
            }

            assignTaskToCollaboration(collabName, username, taskName, dueDate, trimmedDescrip);
        }
        else if (cmd == "list-tasks") 
        {
            MyString collabName;
            if (!(iss >> collabName))
            {
                throw std::runtime_error("Invalid syntax. Use: list-tasks <collaboration name>");
            }
            listCollaborationTasks(collabName);
        }
        else
        {
            std::cout << "Unknown command!" << std::endl;
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void RunProgram::registerUser(const MyString& username, const MyString& password) 
{
    userManager.registerUser(username, password);
    std::cout << "Registered successfully!" << std::endl;
}

void RunProgram::loginUser(const MyString& username, const MyString& password) 
{
    userManager.loginUser(username, password);
    std::cout << "Welcome back, " << username << "!" << std::endl;
}

void RunProgram::addTask(const MyString& name, const MyString& dueDate, const MyString& description)
{
    userManager.addTask(name, dueDate, description);
    std::cout << "Task added successfully!" << std::endl;
}

void RunProgram::getTask(const MyString& ind) 
{
    if (HelperFunctions::isDigit(ind[0]))
    {
        int id = HelperFunctions::myStringToInt(ind.c_str());
        userManager.getTask(id);
    }
    else
    {
        userManager.getTask(ind);
    }
}

void RunProgram::updateTaskName(int id, const MyString& name) 
{
    userManager.updateTaskName(id, name);
    std::cout << "Task name updated successfully!" << std::endl;
}

void RunProgram::startTask(int id)
{
    userManager.startTask(id);
    std::cout << "Task started successfully!" << std::endl;
}

void RunProgram::updateTaskDescription(int id, const MyString& description)
{
    userManager.updateTaskDescription(id, description);
    std::cout << "Task description updated successfully!" << std::endl;
}

void RunProgram::removeTaskFromDashboard(int id) 
{
    userManager.removeTaskFromDashboard(id);
    std::cout << "Task removed from dashboard successfully!" << std::endl;
}

void RunProgram::addTaskToDashboard(int id) 
{
    userManager.addTaskToDashboard(id);
    std::cout << "Task added to dashboard successfully!" << std::endl;
}

void RunProgram::deleteTask(int id) 
{
    userManager.deleteTask(id);
    std::cout << "Task deleted successfully!" << std::endl;
}

void RunProgram::listTasks(const Optional<MyString>& date) 
{
    if (date.containsData())
    {
        userManager.listTasks(date.getData());
    }
    else 
    {
        userManager.listTasks();
    }
}

void RunProgram::listCompletedTasks()
{
    userManager.listCompletedTasks();
}

void RunProgram::listDashboard()
{
    userManager.listDashboard();
}

void RunProgram::finishTask(int id)
{
    userManager.finishTask(id);
    std::cout << "Congratulations on completing the task!" << std::endl;
}

void RunProgram::logout() 
{
    userManager.logoutUser();
    std::cout << "Logged out successfully!" << std::endl;
}

void RunProgram::addCollaboration(const MyString& name)
{
    userManager.addCollaboration(name);
    std::cout << "Collaboration added successfully!" << std::endl;
}

void RunProgram::deleteCollaboration(const MyString& name) 
{
    userManager.deleteCollaboration(name);
    std::cout << "Collaboration deleted successfully!" << std::endl;
}

void RunProgram::listCollaborations() const
{
    userManager.listCollaborations();
}

void RunProgram::addUserToCollaboration(const MyString& collabName, const MyString& username) 
{
    userManager.addUserToCollaboration(collabName, username);
    std::cout << "User added successfully to collaboration!" << std::endl;
}

void RunProgram::assignTaskToCollaboration(const MyString& collabName, const MyString& username, const MyString& taskName, const MyString& dueDate, const MyString& description)
{
    userManager.assignTaskToCollaboration(collabName, username, taskName, dueDate, description);
    std::cout << "Task assigned successfully to " << username << "!" << std::endl;
}

void RunProgram::listCollaborationTasks(const MyString& collabName) const 
{
    userManager.listCollaborationTasks(collabName);
}