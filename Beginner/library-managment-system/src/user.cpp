#include <iostream>
#include <string>
#include "user.h"

using namespace std;


User::User(string usernameIn, string emailIn, string phoneIn)
{
    username = usernameIn;
    email = emailIn;
    phone = phoneIn;
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string usernameIn)
{
    username = usernameIn;
}
string User::getEmail()
{
    return email;
}
void User::setEmail(string emailIn)
{
    email = emailIn;
}
string User::getPhone()
{
    return phone;
}
void User::setPhone(string phoneIn)
{
    phone = phoneIn;
}

