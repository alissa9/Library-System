#ifndef _HASH_H_
#define _HASH_H_

/*
hash.hpp
Author: M00714688
Created : 07/04/2021
Updated : 22/04/2021
*/

#include <iostream>
#include <string>
#include "Book.hpp"

class HashTable
{

    /*defining the table size and the core of the hash table 
     which is a bucket that has a pointer to point at an item*/
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