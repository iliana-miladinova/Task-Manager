#pragma once
#include "MyString.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "PolymorphicPtr.hpp"
#include "Optional.hpp"

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
	Optional<MyString> dueDate;
	Status status;
	MyString description;
public:
	Task();
	Task(int id, const MyString& name, const Optional<MyString>& dueDate, const Status& status, const MyString& description);
	virtual ~Task() = default;

	std::tm getDueDateFromString() const;

	MyString getStringFromStatus() const;
	const MyString& getName() const;
	int getId() const;
	Status getStatus() const;
	virtual void showTask() const;
	void setStatus(const Status& status);
	const Optional<MyString>& getDueDate() const;
	const MyString& getDescription() const;

	virtual void serialize(std::ofstream& ofs) const;
	virtual void deserialize(std::ifstream& ifs);

	virtual Task* clone() const;

	virtual const MyString& getType() const;

	void setName(const MyString& name);
	void setDescription(const MyString& description);

	void startTask();

};
