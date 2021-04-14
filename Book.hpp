
#include <string>
#include <vector>

class Book
{

public:
    Book();
    Book(std::string t, std::vector<std::string> a, std::string i, int q);

    void setTitle(std::string title);
    void setAuthor(std::vector<std::string> authors);
    void setISBN(std::string ISBN);
    void setQuantity(int quantity);
    void printAuthors();


    /*Getter methods*/
    std::string getTitle();
    std::vector<std::string> getAuthor();
    std::string getISBN();
    


    int getQuantity();
    Book *next;

private:
    std::string title;
    std::vector<std::string> authors;
    std::string ISBN;
    int quantity;
};