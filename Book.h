
#include <string>
#include <vector>

class Book
{

public:
    Book(std::string t, std::vector<std::string> a, std::string i, std::string q);

    void printTitle();
    void printAuthor();
    void printISBN();
    void printQuantity();

private:
    std::string title;
    std::vector<std::string> authors;
    std::string ISBN;
    std::string quantity;
};