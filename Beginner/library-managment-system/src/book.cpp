#include <iostream>
#include <string>
#include "user.h"
#include "book.h"

using namespace std;

Book::Book(int idIn, string booknameIn, string authorIn, int yearIn, bool availableIn, string username, string email, string phone)
{
    id = idIn;
    bookname = booknameIn;
    author = authorIn;
    yearOfPublishing = yearIn;
    available = availableIn;
    readBy = new User(username, email, phone);
}
Book::~Book()
{
    delete readBy;
}
string Book::getBookname()
{
    return bookname;
}

void Book::setBookname(string book)
{
    bookname = book;
}
string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string auth)
{
    author = auth;
}
int Book::getYearOfPublishing ()
{
    return yearOfPublishing;
}
void Book::setYearOfPublishing(int year)
{
    yearOfPublishing = year;
}
bool Book::isAvailable()
{
    return available;
}
void Book::setAvailability(bool availab)
{
    available = availab;
}

