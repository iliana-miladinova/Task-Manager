#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "PolymorphicPtr.hpp"
#include "Task.h"
#include "Dashboard.h"

#include "MyString.h"
#include "MyVector.hpp"
#include "PolymorphicPtr.hpp"
#include "Task.h"
#include "Dashboard.h"

class User {
private:
    MyString username;
    MyString password;
    Vector<Polymorphic_Ptr<Task>> tasks; // Vector of pointers to tasks
    Dashboard dashboard;

public:
    User() = default;
    User(const MyString& username, const MyString& password);
    const MyString& getUsername() const;
    const MyString& getPassword() const;
    void addTask(Polymorphic_Ptr<Task> task);
    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;

    void serializeUser(std::ofstream& ofs) const;
    void deserializeUser(std::ifstream& ifs);

    void serializeTasks(std::ofstream& ofs) const;
    void deserializeTasks(std::ifstream& ifs);

    bool checkPassword(const MyString& password) const;
};

//class User {
//private:
//    MyString username;
//    MyString password;
//    Dashboard dashboard;
//    Vector<Polymorphic_Ptr<Task>> tasks; // Vector of pointers to tasks
//   
//public:
//    User() = default;
//    User(const MyString& username, const MyString& password);
//    const MyString& getUsername() const;
//    const MyString& getPassword() const;
//    void addTask(Polymorphic_Ptr<Task> task);
//    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;
//
//    void serializeUser(std::ofstream& ofs) const;
//    void deserializeUser(std::ifstream& ifs);
//
//    void serializeTasks(std::ofstream& ofs) const;
//    void deserializeTasks(std::ifstream& ifs);
//
//    bool checkPassword(const MyString& password) const;
//};

//#include "MyString.h"
//#include "MyVector.hpp"
//#include "PolymorphicPtr.hpp"
//#include "Task.h"
//#include "Dashboard.h"
//#include "HelperFunctions.h"
//
//class User
//{
//protected:
//	MyString username;
//	MyString password;
//	Vector<Polymorphic_Ptr<Task>> tasks; // Вектор от указатели към задачи
//	Dashboard dashboard;
//public:
//	User() = default;
//	User(const MyString& username, const MyString& password);
//	/*virtual ~User() = default;*/
//	const MyString& getUsername() const;
//	const MyString& getPassword() const;
//	void addTask(Polymorphic_Ptr<Task> task);
//	const Vector<Polymorphic_Ptr<Task>>& getTasks() const;
//
//	void serializeUser(std::ofstream& ofs) const;
//	void deserializeUser(std::ifstream& ifs);
//	bool checkPassword(const MyString& password) const;
//
//	const Vector<Polymorphic_Ptr<Task>>& getDashboardTasks() const;
//	void updateDashboard();
//	void login();
//	void removeTaskFromDashboard(int taskId);
//};

//class User {
//private:
//    MyString username;
//    MyString password;
//    Vector<Polymorphic_Ptr<Task>> tasks; // Vector of pointers to tasks
//    Dashboard dashboard;
//
//public:
//    User() = default;
//    User(const MyString& username, const MyString& password);
//    const MyString& getUsername() const;
//    const MyString& getPassword() const;
//    void addTask(Polymorphic_Ptr<Task> task);
//    const Vector<Polymorphic_Ptr<Task>>& getTasks() const;
//
//    void serializeUser(std::ofstream& ofs) const;
//    void deserializeUser(std::ifstream& ifs);
//
//    void serializeTasks(std::ofstream& ofs) const;
//    void deserializeTasks(std::ifstream& ifs);
//
//    bool checkPassword(const MyString& password) const;
//
//};
