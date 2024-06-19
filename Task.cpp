#include "Task.h"
Task::Task()
{
	id = 0;
	name = "";
	dueDate = "";
	status = Status::IN_PROCESS;
	description = "";
}
Task::Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description) :id(id), dueDate(dueDate), name(name),/*dueDate(dueDate),*/status(status), description(description)
{
	//setDueDate(dueDate);
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

//void Task::setDueDate(const MyString& _dueDate)
//{
//   /* if (!isValidDateFormat(_dueDate))
//    {
//        throw std::exception("Invalid date format");
//    }*/
//    this->dueDate = _dueDate;
//}

const MyString& Task::getName() const
{
	return name;
}

MyString Task::getStringFromStatus() const
{
	MyString statusStr;
	switch (status)
	{
	case Status::ON_HOLD:
		statusStr = "ON HOLD";
		break;
	case Status::IN_PROCESS:
		statusStr = "IN PROCESS";
		break;
	case Status::DONE:
		statusStr = "DONE";
		break;
	case Status::OVERDUE:
		statusStr = "OVERDUE";
		break;
	default:
		break;
	}
	return statusStr;
}

void Task::showTask() const
{
	const MyString statusStr = getStringFromStatus();
	std::cout << "Id: " << id << std::endl;
	std::cout << " Name: " << name << std::endl;
	std::cout << " due date: " << dueDate << std::endl;
	std::cout << " status: " << statusStr << std::endl;
	std::cout << " description: " << description << std::endl;
}

int Task::getId() const
{
	return id;
}

Status Task::getStatus() const
{
	return status;
}

void Task::setStatus(const Status& status)
{
	this->status = status;
}

const MyString& Task::getDueDate() const
{
	return dueDate;
}
const MyString& Task::getDescription() const
{
	return description;
}

void Task::serialize(std::ofstream& ofs) const
{
	ofs.write((const char*)&id, sizeof(id));

	size_t nameLen = name.getSize();
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write(name.c_str(), nameLen);

	size_t dueDateLen = dueDate.getSize();
	ofs.write((const char*)&dueDateLen, sizeof(dueDateLen));
	ofs.write(dueDate.c_str(), dueDateLen);

	ofs.write((const char*)&status, sizeof(status));

	size_t descriptionLen = description.getSize();
	ofs.write((const char*)&descriptionLen, sizeof(descriptionLen));
	ofs.write(description.c_str(), descriptionLen);
}

void Task::deserialize(std::ifstream& ifs)
{
	/*ifs.read((char*)&id, sizeof(id));

	size_t nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	char* nameBuffer = new char[nameLen + 1];
	ifs.read(nameBuffer, nameLen);
	nameBuffer[nameLen] = '\0';
	name = MyString(nameBuffer);
	delete[] nameBuffer;

	size_t dueDateLen;
	ifs.read((char*)&dueDateLen, sizeof(dueDateLen));
	char* dueDateBuffer = new char[dueDateLen + 1];
	ifs.read(dueDateBuffer, dueDateLen);
	dueDateBuffer[dueDateLen] = '\0';
	dueDate = MyString(dueDateBuffer);
	delete[] dueDateBuffer;

	ifs.read((char*)&status, sizeof(status));

	size_t descriptionLen;
	ifs.read((char*)&descriptionLen, sizeof(descriptionLen));
	char* descriptionBuffer = new char[descriptionLen + 1];
	ifs.read(descriptionBuffer, descriptionLen);
	descriptionBuffer[descriptionLen] = '\0';
	description = MyString(descriptionBuffer);
	delete[] descriptionBuffer;*/

	ifs.read((char*)&id, sizeof(id));

	size_t nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	char* nameBuffer = new char[nameLen + 1];
	ifs.read(nameBuffer, nameLen);
	nameBuffer[nameLen] = '\0';
	name = MyString(nameBuffer);
	delete[] nameBuffer;

	size_t dueDateLen;
	ifs.read((char*)&dueDateLen, sizeof(dueDateLen));
	char* dueDateBuffer = new char[dueDateLen + 1];
	ifs.read(dueDateBuffer, dueDateLen);
	dueDateBuffer[dueDateLen] = '\0';
	dueDate = MyString(dueDateBuffer);
	delete[] dueDateBuffer;

	ifs.read((char*)&status, sizeof(status));

	size_t descriptionLen;
	ifs.read((char*)&descriptionLen, sizeof(descriptionLen));
	char* descriptionBuffer = new char[descriptionLen + 1];
	ifs.read(descriptionBuffer, descriptionLen);
	descriptionBuffer[descriptionLen] = '\0';
	description = MyString(descriptionBuffer);
	delete[] descriptionBuffer;
}

Task* Task::clone() const
{
	return new Task(*this);
}

const MyString& Task::getType() const
{
	static MyString type = "Task";
	return type;
}