#include "Dashboard.h"

void Dashboard::addTaskToDashboard(int id)
{
	for (size_t i = 0; i < taskIds.getSize(); i++)
	{
		if (taskIds[i]==id)
		{
			throw std::invalid_argument("This task is already in the dashboard!");
		}
	}
	taskIds.pushBack(id);
}

void Dashboard::removeTaskFromDashboard(int id)
{
	for (size_t i = 0; i < taskIds.getSize(); i++)
	{
		if (taskIds[i]==id)
		{
			taskIds.erase(id);
		}
	}
	throw std::invalid_argument("This task does not exist in dashboard!");
}