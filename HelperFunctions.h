#pragma once
#include <ctime>

namespace HelperFunctions
{
	bool compareDates(const std::tm& lhs, const std::tm& rhs)
	{
		if (lhs.tm_year==rhs.tm_year && lhs.tm_mon==rhs.tm_mon && lhs.tm_mday==rhs.tm_mday)
		{
			return true;
		}
		return false;
	}
}