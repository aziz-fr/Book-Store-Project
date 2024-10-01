///Implementation File for class bookType

#include <iostream>
#include <string>
#include "bookType.h"

using namespace std;

void bookType::setBookInfo(string title, string ISBN,
					 string Publisher, int PublishYear,
					 string auth[], double cost, int copies,
					 int authorCount)
{
    int i;
    bookTitle = title;
    bookISBN = ISBN;
    bookPublisher = Publisher;
    bookPublishYear = PublishYear;
    noOfAuthors = authorCount;

    for (i = 0; i < noOfAuthors; i++)
        authors[i] = auth[i];

    price = cost;
    quantity = copies;
}

void bookType::setBookTitle(string s)
{
    bookTitle = s;
}

void bookType::setBookISBN(string s)
{
    bookISBN = s;
}

void bookType::setBookPrice(double cost)
{
    price = cost;
}

void bookType::setCopiesInStock(int noOfCopies)
{
    quantity = noOfCopies;
}

void bookType::printInfo() const
{
    int i;

    cout << "Title: " << bookTitle << endl;
    cout << "ISBN: " << bookISBN << endl;
    cout << "Publisher: " << bookPublisher << endl;
    cout << "Year of Publication: " << bookPublishYear << endl;
    cout << "Number of Authors: " << noOfAuthors << endl;
    cout << "Authors: ";
    for (i = 0; i < noOfAuthors; i++)
        cout << authors[i] << "; ";
    cout << endl;
    cout << "Price: " << price << endl;
    cout << "Quantities in stock: " << quantity << endl;
}

bool bookType::isISBN(string s) const
{
    return (bookISBN == s);
}

bool bookType::isTitle(string s) const
{
    return (bookTitle == s);
}

bool bookType::isAuthor(string s) const
{
    bool found = false;
    int i;

    for (i = 0; i < noOfAuthors; i++)
        if (authors[i] == s)
        {
            found = true;
            break;
        }

    return found;
}

void bookType::getBookTitle(string& s) const
{
    s = bookTitle;
}

void bookType::getBookISBN(string& s) const
{
    s = bookISBN;
}

double bookType::getBookPrice() const
{
    return price;
}

bool bookType::isInStock() const
{
    return (quantity > 0);
}

void bookType::makeSale()
{
    quantity--;
}

void bookType::printBookPrice() const
{
    cout << "Price = " << price << endl;
}

void bookType::printbookTitle() const
{
    cout << "Title: " << bookTitle << endl;
}

void bookType::printbookTitleAndISBN() const
{
    cout << "Title: " << bookTitle << ";  ISBN: " << bookISBN << endl;
}

void bookType::showQuantityInStock() const
{
    cout << "Quantity: " << quantity << endl;
}

void bookType::updateQuantity(int addBooks)
{
    quantity = quantity + addBooks;
}

bookType::bookType()
{
    int i;

    bookTitle = "";
    bookISBN = "";
    bookPublisher = "";

    bookPublishYear = 1900;

    noOfAuthors = 0;

    for (i = 0; i < 4; i++)
        authors[i] = "";

    price = 0;
    quantity = 0;
}
