#include "Task.h"

Task::Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description):id(id),name(name),dueDate(dueDate),status(status),description(description)
{

}

std::tm Task::getDueDateFromString() const
{
	std::tm tm = {};
	std::stringstream ss(dueDate.c_str());
	ss >> std::get_time(&tm, "%d-%m-%Y");
	if (ss.fail())
	{
		throw std::invalid_argument("Incorecct date format. Use DD-MM-YYYY");
	}
	return tm;
}