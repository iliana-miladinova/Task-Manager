#pragma once
#include "MyString.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <fstream>

enum class Status
{
	ON_HOLD,
	IN_PROCESS,
	DONE,
	OVERDUE
};

class Task
{
protected:
	int id;
	MyString name;
	MyString dueDate;
	Status status;
	MyString description;
	/*bool isValidDateFormat(const MyString& date) const;*/

	//void setDueDate(const MyString& _dueDate);
	/*const *//*MyString getStringFromStatus() const;*/
public:
	Task() /*= default*/;
	Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description);
	virtual ~Task() = default;

	std::tm getDueDateFromString() const;
	/*bool isValidDateFormat(const MyString& date) const;*/

	MyString getStringFromStatus() const;
	const MyString& getName() const;
	int getId() const;
	Status getStatus() const;
	virtual void showTask() const;
	void setStatus(const Status& status);
	const MyString& getDueDate() const;
	const MyString& getDescription() const;

	virtual void serialize(std::ofstream& ofs) const;
	virtual void deserialize(std::ifstream& ifs);

	virtual Task* clone() const;

	virtual const MyString& getType() const;

	/*void showTask() const
	{
		const MyString statusStr = getStringFromStatus();
		std::cout << "Id: " << id << std::endl;
		std::cout << " Name: " << name << std::endl;
		std::cout << " due date: " << dueDate << std::endl;
		std::cout << " status: " << statusStr << std::endl;
		std::cout << " description: " << description << std::endl;
	}*/
	/*const MyString& getDate() const;*/
	/*const MyString& getDueDate() const;*/
};