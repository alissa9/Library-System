#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include <vector>
#include <sstream>

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

int main()
{

    // Create a text string, which is used to output the text file
    std::string myText;
    // Read from the text file
    std::ifstream MyReadFile("books");
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
        Book Book1(title, eachAuthor, ISBN, quantity);
        /*to clear vector of the previous line*/
        eachAuthor.clear();

        Book1.printTitle();
        Book1.printAuthor();
        Book1.printISBN();
        Book1.printQuantity();

        // INSERT FUNCTION -> book1
        // int pos = hash(book1.gettitle());
        // hash::insert(book1,pos);
        // hash function
        //
    }

    MyReadFile.close();
};