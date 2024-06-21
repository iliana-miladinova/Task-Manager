#pragma once
#pragma once
#include "Task.h"
#include "MyVector.hpp"
//#include "User.h"

class ProjectTask :public Task
{
private:
	/*Vector<MyString> collaborators;*/
	MyString assignee;
public:
	ProjectTask() = default;
	ProjectTask(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description, const MyString& assignee);

	void serialize(std::ofstream& ofs) const override;
	/*void*/ /*Polymorphic_Ptr<Task>*/ void deserialize(std::ifstream& ifs) override;
	void showTask() const override;

	Task* clone() const override;
	const MyString& getType() const override;
};