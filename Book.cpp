#include "Book.h"
#include <iostream>

Book::Book(string t, string a, string i, string q)
{
    title = t;
    authors = a;
    ISBN = i;
    quantity = q;
}

void Book::printTitle()
{
    cout << title << endl;
}

void Book::printAuthor()
{
    cout << authors << endl;
}

void Book::printISBN()
{
    cout << ISBN << endl;
}

void Book::printQuantity()
{
    cout << quantity << endl;
}