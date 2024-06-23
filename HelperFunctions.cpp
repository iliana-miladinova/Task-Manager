#include "HelperFunctions.h"

namespace HelperFunctions
{
    std::tm getCurrentDate()
    {
        std::time_t t = std::time(nullptr);
        std::tm currentDate = *std::localtime(&t);
        return currentDate;
    }

    bool isDueToday(const std::tm& dueDate)
    {
        std::tm currentDate = getCurrentDate();
        return (currentDate.tm_year == dueDate.tm_year &&
                currentDate.tm_mon == dueDate.tm_mon &&
                currentDate.tm_mday == dueDate.tm_mday);
    }

    bool isOverdue(const std::tm& dueDate)
    {
        std::tm currentDate = getCurrentDate();
        if (currentDate.tm_year > dueDate.tm_year)
        {
            return true;
        }
        if (currentDate.tm_year == dueDate.tm_year && currentDate.tm_mon > dueDate.tm_mon)
        {
            return true;
        }
        if (currentDate.tm_year == dueDate.tm_year && currentDate.tm_mon == dueDate.tm_mon && currentDate.tm_mday > dueDate.tm_mday)
        {
            return true;
        }
        return false;
    }

    std::istream& myGetline(std::istream& is, MyString& str) 
    {
        str = MyString();
        char c;
        while (is.get(c)) {
            if (c == '\n') {
                break;
            }
            char tempStr[2] = { c, '\0' };
            str += MyString(tempStr); 
        }
        return is;
    }

    bool isWhitespace(char c) 
    {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }

    int myStringToInt(const MyString& str) {
        int result = 0;
        bool negative = false;
        size_t i = 0;

        if (str[0] == '-') 
        {
            negative = true;
            i = 1;
        }

        for (size_t i=0; i < str.getSize(); i++)
        {
            char c = str[i];
            if (c < '0' || c > '9') {
                throw std::invalid_argument("Invalid character in MyString for conversion to int");
            }
            result = result * 10 + (c - '0');
        }

        return negative ? -result : result;
    }

    bool isDigit(char c) 
    {
        return c >= '0' && c <= '9';
    }
}