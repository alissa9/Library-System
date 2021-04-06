#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include <vector>

using namespace std;

int main()
{

    // Create a text string, which is used to output the text file
    string myText;
    // Read from the text file
    ifstream MyReadFile("books");
    // Use a while loop together with the getline() function to read the file line by line

    string title, authors, ISBN, quantity;
    vector<string> eachAuthor;

    // splitting the books file
    while (getline(MyReadFile, myText))
    {
        getline(MyReadFile, title, '\t');
        getline(MyReadFile, authors, '\t');
        getline(MyReadFile, ISBN, '\t');
        getline(MyReadFile, quantity, '\t');
        cout << "\n";
        cout << title << endl
             << authors << endl
             << ISBN << endl
             << quantity << endl;
    }
    MyReadFile.close();

    Book Book1(title, authors, ISBN, quantity);
    Book1.printTitle();
};