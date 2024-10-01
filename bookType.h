///header file for class bookType

#include <string>
using namespace std;

class bookType
{
public:
    void setBookInfo(string title, string ISBN, string Publisher,
                     int PublishYear, string auth[], double cost,
                     int copies, int noAuthors);  // initialize book information
    void setBookTitle(string s);  // set book title to s
    void setBookISBN(string s);   // set book ISBN to s
    void setBookPrice(double cost); // set book price to cost
    void setCopiesInStock(int noOfCopies);

    void printInfo() const; // print all the information for class bookType

    bool isISBN(string s) const;    //search ISBN
    bool isTitle(string s) const;   //search Title
    bool isAuthor(string s) const;  //search author name

    void getBookTitle(string& s) const;  //get book title from setBookTitle s
    void getBookISBN(string& s) const;  //get book ISBN from setBookISBN s
    double getBookPrice() const;    //get cost from setBookInfo

    bool isInStock() const; //check quantity of book
    void makeSale();

    void printBookPrice() const;    //print book price
    void printbookTitle() const;    //print book price
    void printbookTitleAndISBN() const;  //print Title and ISBN
    void showQuantityInStock() const;   //show number of book in stock
    void updateQuantity(int addBooks);  //add more book in stock

    bookType(); //constructor

private:
    string bookTitle;
    string bookISBN;
    string bookPublisher;

    int bookPublishYear;
    string authors[4];

    double price;
    int quantity;

    int noOfAuthors;
};
