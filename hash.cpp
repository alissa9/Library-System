/*
hash.cpp
Author: M00714688
Created : 07/04/2021
Updated : 29/04/2021
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

/*The Inserting function passes the books constructor to the Hash function 
then overwriting the empty values to insert thme in the HashTable   */
void HashTable::AddBook(Book book)
{
    /* this position variable holds the loaction of the hash 
     where I am storing the information  */
    int position = Hash(book.getTitle());
    /*Checking if the bucket -first element of the default constructor
     bucket of the hash table is empty so it is a place holder then 
     overwriting the values*/
    if (BooksTable[position]->getTitle() == "Empty")
    {
        BooksTable[position]->setTitle(book.getTitle());
        BooksTable[position]->setAuthor(book.getAuthor());
        BooksTable[position]->setISBN(book.getISBN());
        BooksTable[position]->setQuantity(book.getQuantity());
        BooksTable[position]->next = nullptr;
    }
    /*initializing the newbook that holds the values then points to null*/
    else
    {
        /*a pointer to point to the first position*/
        Book *ptr = BooksTable[position];
        Book *newBook = new Book;

        newBook->setTitle(book.getTitle());
        newBook->setAuthor(book.getAuthor());
        newBook->setISBN(book.getISBN());
        newBook->setQuantity(book.getQuantity());
        newBook->next = nullptr;

        /*while the next element isnt pointing to null 
         then the advancing the pointer on the list untill it gets 
         to the last item stored in the hash table*/
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        /*finally linking the last item in the list to the new created item */
        ptr->next = newBook;
    }
}

/*this hash function takes a string then converts it to an integer
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

/*The Search fucntion looks for the searched value in the data by the key "Titles" */
void HashTable::SearchBook(std::string key)
{
    /*passsing the key into the Hash fucntion to return the bucket*/
    int position = Hash(key);

    /*pointing to the first item of the bucket*/
    Book *Ptr = BooksTable[position];
    /*Scanning the entire list then if its found it will print out the values of the item*/

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
        /*this will keep moving the item inside the list 
        untill the pointer is passed through the whole list*/
        Ptr = Ptr->next;
    }
}

/* The Remove function looks in the data structure for the searched value 
   then if it found it will sets a poiter to delete the value from the 
   data structure */
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

    /* chekcing if the title = a title and the book object is pointing to null 
    so there is no collisons */
    else if (BooksTable[position]->getTitle() == key && BooksTable[position]->next == nullptr)
    {
        BooksTable[position]->getTitle() = "Empty";
    }
    /*checking if there is a match then setting the delete 
     pointer to point to the book position 
     * then setting the postion to point to the book object
     finally it will delete the book object  */
    else if (BooksTable[position]->getTitle() == key)
    {

        delPtr = BooksTable[position];
        BooksTable[position] = BooksTable[position]->next;
        delete delPtr;
        std::cout << "The Book was Removed from the data \n " << std::endl;
    }
    /*Here it will have to go through the linked list */
    else
    {
        Pointer1 = BooksTable[position]->next;
        Pointer2 = BooksTable[position];
        /* the loop will keep looping as long as
         its not pointing to null and there is no match */
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