#pragma once
#include "MyString.h"
#include <fstream>
#include "HelperFunctions.h"

class User
{
protected:
	MyString username;
	MyString password;
public:
	User() = default;
	User(const MyString& username, const MyString& password);
	virtual ~User() = default;
	const MyString& getUsername() const;
	const MyString& getPassword() const;

	virtual void serializeUser(std::ofstream& ofs) const;
	virtual void deserializeUser(std::ifstream& ifs);

	virtual const MyString& getUserType() const = 0;

	bool checkPassword(const MyString& password) const;
	/*void saveTasks() const;
	void loadTasks();*/
};
