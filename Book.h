
#include <string>

using namespace std;

class Book
{

public:
    Book(string t, string a, string i, string q);
  

    void printTitle();
    void printAuthor();
    void printISBN();
    void printQuantity();

private:
    string title;
    string authors;
    string ISBN;
    string quantity;
};