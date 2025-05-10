#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
    private:
        int id;
        string bookname;
        string author;
        int yearOfPublishing;
        bool available;
        User* readBy;

    public:
        Book(int idIn, string booknameIn, string authorIn, int yearIn, bool availableIn, string username, string email, string phone);
        ~Book();
        string getBookname();
        void setBookname(string book);
        string getAuthor();
        void setAuthor(string auth);
        int getYearOfPublishing ();
        void setYearOfPublishing(int year);
        bool isAvailable();
        void setAvailability(bool availab);
};

#endif
