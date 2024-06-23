#pragma once
#include "Task.h"
#include "MyVector.hpp"

class ProjectTask :public Task
{
private:
	MyString assignee;
public:
	ProjectTask();
	ProjectTask(int id, const MyString& name, const Optional<MyString>& dueDate, const Status& status, const MyString& description, const MyString& assignee);

	void serialize(std::ofstream& ofs) const override;
	void deserialize(std::ifstream& ifs) override;
	void showTask() const override;

	Task* clone() const override;
	const MyString& getType() const override;
};