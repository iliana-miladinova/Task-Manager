#pragma once
#include <ctime>
#include <fstream>
#include "MyString.h"
#pragma warning(disable : 4996)

namespace HelperFunctions
{
    std::tm getCurrentDate();

    bool isDueToday(const std::tm& dueDate);

    bool isOverdue(const std::tm& dueDate);

    std::istream& myGetline(std::istream& is, MyString& str);

    bool isWhitespace(char c);

    int myStringToInt(const MyString& str);

    bool isDigit(char c);
}