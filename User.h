#pragma once
#include "Task.h"
#include "MyString.h"
#include "MyVector.hpp"

class User
{
private:
	MyString username;
	MyString password;

	Vector<Task> tasks;
	Vector<Task> dashboardTasks;
	Vector<MyString> colaborations;

	void updateDashBoardTask();
public:
	User(const MyString& username, const MyString& password);

	const MyString& getUsername() const;
	const MyString& getPassword() const;

	bool checkPassword(const MyString& password) const;
	
	/*void addTask(const Task& task);*/
	void addTask(const MyString& name, const MyString& dueDate, const MyString& description);
};