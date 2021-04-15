#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include "hash.hpp"

/*splitting the authors that it takes the authors string and the delimm
 nthe out is the vector stores each author when splitting*/
void split_string(std::string const &str, const char delim,
                  std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

int main(int argc, char **argv)
{
    // std::ofstream MyFile("results.txt");

    HashTable hash;

    // Create a text string, which is used to output the text file
    std::string myText;
    // Read from the text file
    std::ifstream MyReadFile(argv[1]);

    // Use a while loop together with the getline() function to read the file line by line

    std::string title, authors, ISBN, quantity;
    std::vector<std::string> eachAuthor;

    // splitting the books file then goes
    while (std::getline(MyReadFile, myText))
    {
        std::stringstream ss(myText);
        getline(ss, title, '\t');
        getline(ss, authors, '\t');
        getline(ss, ISBN, '\t');
        getline(ss, quantity, '\t');

        /* definning the delim then parsing the string of authors seprated by delim
        then storing them into a variable */
        const char delim = ';';
        std::vector<std::string> out;
        split_string(authors, delim, out);

        for (auto &authors : out)
        {
            eachAuthor.push_back(authors);
        }
        Book Book1(title, eachAuthor, ISBN, std::stoi(quantity));
        /*to clear vector of the previous line*/
        hash.AddBook(Book1);

        // MyFile << hash.printTable(Book1) << " " << hash.Hash(Book1.getTitle()) << "\n";
        eachAuthor.clear();
    }
    // MyFile.close();
    MyReadFile.close();
    while (true)
    {
        int selected;
        std::cout << "Welcome To The Online Library" << std::endl;
        std::cout << "-----------MENU---------" << std::endl;
        std::cout << "Search Book by Title....1" << std::endl;
        std::cout << "Add Book................2" << std::endl;
        std::cout << "Remove Book.............3" << std::endl;
        std::cout << "Select an option > " << std::endl;
        std::cin >> selected;

        if (selected == 1)
        {
            std::string title;
            std::cout << "\n Enter Book Title ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);
            hash.SearchBook(title);
        }
        else if (selected == 2)
        {
            std::string title, ISBN, temp;
            int qty;
            std::vector<std::string> listofauthors;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Name of Book" << std::endl;
            std::getline(std::cin, title);

            std::cout << "Enter Authors of Book" << std::endl;
            std::getline(std::cin, temp);
            listofauthors.push_back(temp);

            std::cout << "Enter the ISBN " << std::endl;
            std::getline(std::cin, ISBN);

            std::cout << "Enter the Quantity" << std::endl;
            std::cin >> qty;

            Book newBook = Book(title, listofauthors, ISBN, qty);

            hash.AddBook(newBook);
            hash.SearchBook(newBook.getTitle());
        }
        else if (selected == 3)
        {
            std::string title;
            std::cout << "Enter Book Title to Remove the Book";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);
            // hash.SearchBook(title);
            hash.RemoveBook(title);
        }
    }

    return 0;
};