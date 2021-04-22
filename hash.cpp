/*
hash.cpp: it has the hash functions and table.
Author: M00714688
Created : 07/04/2021
Updated : 22/04/2021
*/
#include <iostream>
#include "hash.hpp"

HashTable::HashTable()
{
    std::vector<std::string> listOfAuthors;
    /* A default value for each element in the table*/
    for (int i = 0; i < SIZE; i++)
    {
        BooksTable[i] = new Book;
        BooksTable[i]->setTitle("Empty");
        BooksTable[i]->setAuthor(listOfAuthors);
        BooksTable[i]->setISBN("Empty");
        BooksTable[i]->setQuantity(0);
    }
}

void HashTable::AddBook(Book book)
{

    /*checking if the position is empty then add the details*/
    int position = Hash(book.getTitle());
    if (BooksTable[position]->getTitle() == "Empty")
    {
        BooksTable[position]->setTitle(book.getTitle());
        BooksTable[position]->setAuthor(book.getAuthor());
        BooksTable[position]->setISBN(book.getISBN());
        BooksTable[position]->setQuantity(book.getQuantity());
        BooksTable[position]->next = nullptr;
    }
    else
    {
        // macking a pointer to point to the first position
        Book *ptr = BooksTable[position];
        Book *newBook = new Book;

        newBook->setTitle(book.getTitle());
        newBook->setAuthor(book.getAuthor());
        newBook->setISBN(book.getISBN());
        newBook->setQuantity(book.getQuantity());
        newBook->next = nullptr;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newBook;
    }
}

int HashTable::Hash(std::string key)
{

    int hash = 0;
    int index;
    // My Name is
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % this->SIZE;
    return index;
}

std::string HashTable::printTable(Book b)
{
    int pos = Hash(b.getTitle());
    std::string s = this->BooksTable[pos]->getTitle();
    return s;
}

void HashTable::SearchBook(std::string key)
{
    int position = Hash(key);

    Book *Ptr = BooksTable[position];
    while (Ptr != nullptr)
    {
        if (Ptr->getTitle() == key)
        {
            std::cout << "Results Found - Title    : " << Ptr->getTitle() << std::endl;
            std::cout << "                ISBN     : " << Ptr->getISBN() << std::endl;
            std::cout << "                Quantity : " << Ptr->getQuantity() << std::endl;
            std::cout << "                Authors  : ";
            Ptr->printAuthors();

            break;
        }
        Ptr = Ptr->next;
    }
}

void HashTable::RemoveBook(std::string key)
{
    int position = Hash(key);
    Book *delPtr;
    Book *Pointer1;
    Book *Pointer2;

    if (BooksTable[position]->getTitle() == "Empty")
    {
        std::cout << "The Book was not found in the data \n " << std::endl;
    }
    else if (BooksTable[position]->getTitle() == key && BooksTable[position]->next == nullptr)
    {
        BooksTable[position]->getTitle() = "Empty";
    }
    else if (BooksTable[position]->getTitle() == key)
    {

        delPtr = BooksTable[position];
        BooksTable[position] = BooksTable[position]->next;
        delete delPtr;
        std::cout << "The Book was Removed from the data \n " << std::endl;
    }
    else
    {
        Pointer1 = BooksTable[position]->next;
        Pointer2 = BooksTable[position];
        while (Pointer1 != nullptr && Pointer1->getTitle() != key)
        {
            Pointer2 = Pointer1;
            Pointer1 = Pointer1->next;
        }
        if (Pointer1 == nullptr)

        {
            std::cout << "The Book was not found in the data \n " << std::endl;
        }
        else
        {
            delPtr = Pointer1;
            Pointer1 = Pointer1->next;
            Pointer2->next = Pointer1;
            delete delPtr;
            std::cout << "The Book was Removed from the data \n " << std::endl;
        }
    }
}