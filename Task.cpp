#include "Task.h"

Task::Task(int id, const MyString& name, const MyString& dueDate, const Status& status, const MyString& description):id(id),dueDate(dueDate), name(name),/*dueDate(dueDate),*/status(status),description(description)
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

//bool Task::isValidDateFormat(const MyString& date) const{
//    // �������� �� ������� ������ �� ������ (DD-MM-YYYY)
//    if (date.getSize() != 10) // ��������� ������ �� ���� 10 ������� �� ������� DD-MM-YYYY
//        return false;
//
//    for (int i = 0; i < 10; ++i) {
//        if (i == 2 || i == 5) {
//            if (date[i] != '-') // �������� �� ������� �� ������ � ��������� 2 � 5
//                return false;
//        }
//        else {
//            if (!isdigit(date[i])) // �������� ���� ������ �������� ������� �� �����
//                return false;
//        }
//    }
//    return true;
//
//    //// �������� �� ������� ������� ��������� �� ���, ����� � ������
//    //int day = stoi(date.substr(0, 2));
//    //int month = stoi(date.substr(3, 2));
//    //int year = stoi(date.substr(6, 4));
//
//    //if (month < 1 || month > 12) // �������� �� ������� �����
//    //    return false;
//
//    //if (day < 1 || day > 31) // �������� �� ������� ���
//    //    return false;
//
//    //// �������� �� ������� ������ (������ �� �������� ������������ �������� �� ��������, ��� � ����������)
//    //if (year < 1900 || year > 2100)
//    //    return false;
//
//    //return true;
//}
//////const MyString& Task::getDueDate() const
//////{
//////    if (!isValidDateFormat(dueDate))
//////    {
//////        throw std::exception("Invalid date format");
//////    }
//////	return dueDate;
////}