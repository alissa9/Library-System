#include "Book.h"
#include <iostream>

Book::Book(std::string t, std::vector<std::string> a, std::string i, std::string q)
{
    title = t;
    authors = a;
    ISBN = i;
    quantity = q;
}

void Book::printTitle()
{
    std::cout << title << std::endl;
}

void Book::printAuthor()
{
    std::cout << "Authors : ";
    for (size_t i = 0; i < authors.size(); i++)
    {
        std::cout << authors.at(i) + "\n";
    }
}

void Book::printISBN()
{
    std::cout << ISBN << std::endl;
}

void Book::printQuantity()
{
    std::cout << quantity << std::endl;
}