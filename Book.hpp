
/*
book.hpp
Author: M00714688
Created : 07/04/2021
Updated : 22/04/2021
*/

#include <string>
#include <vector>

class Book
{

private:
    std::string title;
    std::vector<std::string> authors;
    std::string ISBN;
    int quantity;

public:
    Book();
    Book(std::string t, std::vector<std::string> a, std::string i, int q);
    void setTitle(std::string title);
    void setAuthor(std::vector<std::string> authors);
    void setISBN(std::string ISBN);
    void setQuantity(int quantity);
    void printAuthors();

    /*Callling the Getters methods*/
    std::string getTitle();
    std::vector<std::string> getAuthor();
    std::string getISBN();
    int getQuantity();
    Book *next;
};