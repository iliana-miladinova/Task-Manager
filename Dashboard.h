#pragma once
#include "MyVector.hpp"
class Dashboard
{
private:
	Vector<int> taskIds;
public:
	void addTaskToDashboard(int id);
	void removeTaskFromDashboard(int id);
};