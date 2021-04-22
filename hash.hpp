
/*
hash.hpp: the header file of hash table
Author: M00714688
Created : 07/04/2021
Updated : 22/04/2021
*/

#include <iostream>
#include <string>
#include "Book.hpp"

#ifndef HASH_H
#define HASH_H

class HashTable
{

private:
    static const int SIZE = 317;

    Book *BooksTable[SIZE];

public:
    HashTable();
    int Hash(std::string key);
    void AddBook(Book book);
    std::string printTable(Book b);
    void SearchBook(std::string key);
    void RemoveBook(std::string key);
};
#endif