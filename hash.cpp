
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
