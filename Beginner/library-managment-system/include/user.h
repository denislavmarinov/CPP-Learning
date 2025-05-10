#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    private:
        string username;
        string email;
        string phone;

    public:
        User(string usernameIn, string emailIn, string phoneIn);
        string getUsername();
        void setUsername(string usernameIn);
        string getEmail();
        void setEmail(string emailIn);
        string getPhone();
        void setPhone(string phoneIn);
};

#endif
