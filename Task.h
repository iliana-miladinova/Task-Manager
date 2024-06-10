#pragma once
#include "MyString.h"
#include <ctime>
#include <sstream>
#include <iomanip>

enum class Status
{
	ON_HOLD, 
	IN_PROCESS, 
	DONE, 
	OVERDUE
};

//struct Task
//{
//	int id;
//	MyString string;
//	MyString dueDate;
//	Status status;
//	MyString descriptiom;
//
//	std::tm getDueDateFromString() const
//	{
//		std::tm tm = {};
//		std::stringstream ss(dueDate.c_str());
//		ss >> std::get_time(&tm, "%d-%m-%Y");
//		if (ss.fail())
//		{
//			throw std::invalid_argument("Incorecct date format. Use DD-MM-YYYY");
//		}
//		return tm;
//	}
//
//};

class Task
{
private:
	int id;
	MyString name;
	MyString dueDate;
	Status status;
	MyString description;
public:
	Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description);
	std::tm getDueDateFromString() const;
};