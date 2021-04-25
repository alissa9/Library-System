/*
hash.cpp: it has the hash algorithms and functions.
Author: M00714688
Created : 07/04/2021
Updated : 25/04/2021
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
    /*checking if the position is empty then add the values*/
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
/*this hash function takes a string then converts it to an integere 
 to store the values associated to keys  */
int HashTable::Hash(std::string key)
{
    int hash = 0;
    int index;
    /*this will add up all the value to then store it in the hash  */
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

    /* checking if its empty*/ 
    if (BooksTable[position]->getTitle() == "Empty")
    {
        std::cout << "The Book was not found in the data \n " << std::endl;
    }

    /* chekcing if the title = a title and the book object is poiting to null 
    so that means there is no collisons */
    else if (BooksTable[position]->getTitle() == key && BooksTable[position]->next == nullptr)
    {
        BooksTable[position]->getTitle() = "Empty";
    }
    /*checking if there is a match then setting the delete 
     pointer to point to the book position 
     123then setting the postion to point to the book object
     124 then it will delete the book object  */
    else if (BooksTable[position]->getTitle() == key)
    {

        delPtr = BooksTable[position];
        BooksTable[position] = BooksTable[position]->next;
        delete delPtr;
        std::cout << "The Book was Removed from the data \n " << std::endl;
    }
    /*other wise it will have to go through the linked list */
    else
    {
        Pointer1 = BooksTable[position]->next;
        Pointer2 = BooksTable[position];
        /* the loop will keep looping as long as
         its not pointing to null and there is no match   */
        while (Pointer1 != nullptr && Pointer1->getTitle() != key)
        {
            Pointer2 = Pointer1;
            Pointer1 = Pointer1->next;
        }
       /*if the pointer is pointing to null then there is no match*/
        if (Pointer1 == nullptr)

        {
            std::cout << "The Book was not found in the data \n " << std::endl;
        }
        /*when there is match*/
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