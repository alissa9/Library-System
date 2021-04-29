
/*
book.cpp
Author: M00714688
Created : 07/04/2021
Updated : 22/04/2021
*/

#include "Book.hpp"
#include <iostream>

Book::Book()
{
}
/*the Book Constructor with the Getters and Getters methods.*/
Book::Book(std::string t, std::vector<std::string> a, std::string i, int q)
{
    title = t;
    authors = a;
    ISBN = i;
    quantity = q;
}

/*Setters methods*/
void Book::setTitle(std::string title)
{
    this->title = title;
}

void Book::setAuthor(std::vector<std::string> author)
{

    this->authors = author;
}
void Book::printAuthors()
{
    for (size_t i = 0; i < this->authors.size(); i++)
    {
        std::cout << this->authors.at(i) + " - ";
    }
}

void Book::setISBN(std::string ISBN)
{
    this->ISBN = ISBN;
}

void Book::setQuantity(int quantity)
{
    this->quantity = quantity;
}

/*Getters methods*/
std::string Book::getTitle()
{
    return this->title;
}
std::vector<std::string> Book::getAuthor()

{

    return this->authors;
}

std::string Book::getISBN()
{
    return this->ISBN;
}

int Book::getQuantity()
{
    return this->quantity;
}
