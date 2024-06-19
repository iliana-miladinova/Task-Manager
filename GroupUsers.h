#pragma once
#include "User.h"
#include "MyVector.hpp"

class GroupUsers : public User {
private:
    Vector<MyString> memberUsernames; // Потребителски имена на членовете на групата

public:
    GroupUsers() = default;
    GroupUsers(const MyString& username, const MyString& password);

    void addMember(const MyString& memberUsername);
    const Vector<MyString>& getMembers() const;

    void serializeUser(std::ofstream& ofs) const override;
    void deserializeUser(std::ifstream& ifs) override;

    const MyString& getUserType() const override;
};