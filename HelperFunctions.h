#pragma once
#include <ctime>
#pragma warning(disable : 4996)

namespace HelperFunctions
{
    std::tm getCurrentDate();

    bool isDueToday(const std::tm& dueDate);

    bool isOverdue(const std::tm& dueDate);
}