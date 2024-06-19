#include "HelperFunctions.h"

namespace HelperFunctions
{
    std::tm getCurrentDate() {
        std::time_t t = std::time(nullptr);
        std::tm currentDate = *std::localtime(&t);
        return currentDate;
    }

    bool isDueToday(const std::tm& dueDate) {
        std::tm currentDate = getCurrentDate();
        return (currentDate.tm_year == dueDate.tm_year &&
            currentDate.tm_mon == dueDate.tm_mon &&
            currentDate.tm_mday == dueDate.tm_mday);
    }

    bool isOverdue(const std::tm& dueDate) {
        std::tm currentDate = getCurrentDate();
        if (currentDate.tm_year > dueDate.tm_year) return true;
        if (currentDate.tm_year == dueDate.tm_year && currentDate.tm_mon > dueDate.tm_mon) return true;
        if (currentDate.tm_year == dueDate.tm_year && currentDate.tm_mon == dueDate.tm_mon &&
            currentDate.tm_mday > dueDate.tm_mday) return true;
        return false;
    }
}