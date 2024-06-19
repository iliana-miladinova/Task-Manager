#include "User.h"

User::User(const MyString& username, const MyString& password) :username(username), password(password)
{

}

const MyString& User::getUsername() const
{
	return username;
}

const MyString& User::getPassword() const
{
	return password;
}

void User::serializeUser(std::ofstream& ofs) const
{
	size_t usernameLen = username.getSize();
	ofs.write((const char*)&usernameLen, sizeof(usernameLen));
	ofs.write(username.c_str(), usernameLen);
	size_t passwordLen = password.getSize();
	ofs.write((const char*)&passwordLen, sizeof(passwordLen));
	ofs.write(password.c_str(), passwordLen);

}

void User::deserializeUser(std::ifstream& ifs) 
{
    size_t usernameLen;
    ifs.read((char*)&usernameLen, sizeof(usernameLen));
    char* usernameBuffer = new char[usernameLen + 1];
    ifs.read(usernameBuffer, usernameLen);
    usernameBuffer[usernameLen] = '\0';
    username = MyString(usernameBuffer);
    delete[] usernameBuffer;

    size_t passwordLen;
    ifs.read((char*)&passwordLen, sizeof(passwordLen));
    char* passwordBuffer = new char[passwordLen + 1];
    ifs.read(passwordBuffer, passwordLen);
    passwordBuffer[passwordLen] = '\0';
    password = MyString(passwordBuffer);
    delete[] passwordBuffer;
}


bool User::checkPassword(const MyString& password) const 
{
    return this->password == password;
}

//void User::loadTasks() {
//    std::ifstream inFile((username + "tasks.dat").c_str(), std::ios::binary);
//    if (!inFile) return;
//
//    size_t tasksCount;
//    inFile.read(reinterpret_cast<char*>(&tasksCount), sizeof(tasksCount));
//    tasks.clear();
//
//    for (size_t i = 0; i < tasksCount; i++) {
//        Polymorphic_Ptr<Task> task = Task::deserialize(inFile);
//        tasks.pushBack(task);
//    }
//
//    inFile.close();
//}