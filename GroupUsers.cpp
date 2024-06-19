#include "GroupUsers.h"

GroupUsers::GroupUsers(const MyString& username, const MyString& password)
    : User(username, password) {}

void GroupUsers::addMember(const MyString& memberUsername) {
    memberUsernames.pushBack(memberUsername);
}

const Vector<MyString>& GroupUsers::getMembers() const {
    return memberUsernames;
}

void GroupUsers::serializeUser(std::ofstream& ofs) const {
    User::serializeUser(ofs);

    size_t membersCount = memberUsernames.getSize();
    ofs.write((const char*)&membersCount, sizeof(membersCount));
    for (size_t i = 0; i < membersCount; ++i) {
        size_t usernameLen = memberUsernames[i].getSize();
        ofs.write((const char*)&usernameLen, sizeof(usernameLen));
        ofs.write(memberUsernames[i].c_str(), usernameLen);
    }
}

void GroupUsers::deserializeUser(std::ifstream& ifs) {
    User::deserializeUser(ifs);

    size_t membersCount;
    ifs.read((char*)&membersCount, sizeof(membersCount));
    memberUsernames.clear();
    for (size_t i = 0; i < membersCount; ++i) {
        size_t usernameLen;
        ifs.read((char*)&usernameLen, sizeof(usernameLen));
        char* usernameBuffer = new char[usernameLen + 1];
        ifs.read(usernameBuffer, usernameLen);
        usernameBuffer[usernameLen] = '\0';
        memberUsernames.pushBack(MyString(usernameBuffer));
        delete[] usernameBuffer;
    }
}

const MyString& GroupUsers::getUserType() const 
{
    static MyString type = "GroupUser";
    return type;
}