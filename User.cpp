#include "User.h"

#include "HelperFunctions.h"

User::User(const MyString& username, const MyString& password) :username(username), password(password)
{

}

const MyString& User::getUsername() const
{
	return username;
}

const MyString& User::getPassword() const
{
	return password;
}


bool User::checkPassword(const MyString& password) const
{
	return this->password == password;
}

void User::addTask(const MyString& name, const MyString& dueDate, const MyString& description)
{
	Task tempTask(0, name, dueDate, Status::ON_HOLD, description); 
	tempTask.getDueDateFromString(); 
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		if (tasks[i].getName() == name && HelperFunctions::compareDates(tasks[i].getDueDateFromString(), tempTask.getDueDateFromString()))
		{
			throw std::invalid_argument("Task with this name and due date already exists!");
		}
		/*updateDashBoardTask();*/
	}
	int newId = tasks.getSize() + 1; 
	Task newTask(newId, name, dueDate, Status::ON_HOLD, description);
	tasks.pushBack(newTask);
}

////void User::addTask(/*const Task& task*/
//void User::addTask(const MyString& name, const MyString& dueDate, const MyString& description)
//{
//	//int newId = tasks.getSize() + 1;  // Генериране на нов уникален ID
//	//Task newTask(newId, name, dueDate, Status::ON_HOLD, description);
//	/*try
//	{*/
//		Task tempTask(0, name, dueDate, Status::ON_HOLD, description); // временно създаваме задача за проверка на датата
//		tempTask.getDueDateFromString(); //
//		for (size_t i = 0; i < tasks.getSize(); i++)
//		{
//			/*if (HelperFunctions::compareDates(task.getDueDateFromString(),tasks[i].getDueDateFromString()) && task.getName()==tasks[i].getName())
//			{
//				throw std::invalid_argument("Task with thIS name and due date already exists!");
//			}*/
//			/*if (newTask.getName() == tasks[i].getName() && HelperFunctions::compareDates(newTask.getDueDateFromString(), tasks[i].getDueDateFromString()))
//			{
//				throw std::invalid_argument("Task with this name and due date already exists!");
//			}*/
//			if (tasks[i].getName() == name && HelperFunctions::compareDates(tasks[i].getDueDateFromString(), tempTask.getDueDateFromString())) 
//			{
//				throw std::invalid_argument("Task with this name and due date already exists!");
//			}
//
//			//int newId = tasks.getSize() + 1;  // Генериране на нов уникален ID
//			//Task newTask(newId, name, dueDate, Status::ON_HOLD, description);
//			/*tasks.pushBack(newTask);*/
//			/*tasks.pushBack(task);
//			updateDashBoardTask();*/
//		}
//		int newId = tasks.getSize() + 1; // Генериране на нов уникален ID
//		Task newTask(newId, name, dueDate, Status::ON_HOLD, description);
//		tasks.pushBack(newTask);
//	//}
//	//catch (const std::invalid_argument& e) 
//	//{
//	//	std::cout << e.what() << std::endl;
//	//	throw; // препредаваме изключението нагоре
//	//}
//}