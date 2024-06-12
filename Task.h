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

class Task
{
private:
	int id;
	MyString name;
	MyString dueDate;
	Status status;
	MyString description;
	/*bool isValidDateFormat(const MyString& date) const;*/

	//void setDueDate(const MyString& _dueDate);
	const MyString& getStringFromStatus() const;
public:
	Task() = default;
	Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description);
	std::tm getDueDateFromString() const;
	/*bool isValidDateFormat(const MyString& date) const;*/

	const MyString& getName() const;
	void showTask() const;
	/*const MyString& getDueDate() const;*/
};