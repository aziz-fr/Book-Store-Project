/**
    Name: Aziz Ahmed
    CIS 251 Project 5A
**/
#include <iostream>
#include <string>
#include <fstream>
#include "bookType.h"

using namespace std;

void getBookData(bookType books[], int& numOfBooks);
void printBookData(bookType books[], int noOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
                         int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title,
                            int& loc);
void updateCopiesInStock(bookType books[], int bookCount);
void showMenu();
void subMenu();

int main()
{
    bookType books[100] = {};

    int numberOfBooks = 0;
    int choice; //user's choice
    int i;  //variable used in for loop

    getBookData(books, numberOfBooks);  //stored data from File

    showMenu();
    cin >> choice;

    while(choice != 9)
    {
    switch (choice)
    {
		case 1:
            for (i = 0; i < numberOfBooks; i++){
                books[i].printbookTitle();
                }
            cout << endl;
            break;
		case 2:
            for (i = 0; i < numberOfBooks; i++){
                books[i].printbookTitleAndISBN();
                }
            cout << endl;
            break;
		case 3:
		    {
            searchBookData(books, numberOfBooks);
		    }
            break;
		case 4:
		    {
            updateCopiesInStock(books, numberOfBooks);
		    }
            break;
		case 5:
		    {
            printBookData(books, numberOfBooks);
		    }
            break;
		default:
            cout << "Invalid selection." << endl;
        }

        showMenu();
        cin >> choice;
    }

    return 0;
}

void getBookData(bookType books[], int& noOfBooks)
{
    string title;
    string ISBN;
    string Publisher;
    int PublishYear;
    string auth[4];
    double cost;
    int copies;
    int noOfAuthors;
    char ch;

    ifstream File;
    File.open("bookData.txt");

    if(!File.is_open())
    {
        cout << "Error Opening File\n";
        cout << "Program Terminated\n";
        return;
    }

    File >> noOfBooks;  //number of books from first line
    File.get(ch);

    for (int i = 0; i < noOfBooks; i++)
    {
        getline(File, title);
        getline(File, ISBN);
        getline(File, Publisher);
        File >> PublishYear >> cost >> copies >> noOfAuthors;
        File.get(ch);

        for (int p = 0; p < noOfAuthors; p++)
        {
            getline(File, auth[p]);
        }  //end second for loop
        //storing all data from File into setBookInfo.
        books[i].setBookInfo(title, ISBN, Publisher, PublishYear, auth, cost, copies, noOfAuthors);
    } //end for first loop
}

void printBookData(bookType books[], int noOfBooks)
{
    for (int i = 0; i < noOfBooks; i++)
    {
        books[i].printInfo();
    }
}

void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
                         int& loc)
{
    int i;
    loc = -1;

    for (i = 0; i < bookCount; i++)
        if (books[i].isISBN(ISBN))
        {
            loc = i;
            break;
        }
}

void searchBookDataByTitle(bookType books[], int bookCount, string title,
                            int& loc)
{
    int i;
    loc = -1;


    for (i = 0; i < bookCount; i++)
        if (books[i].isTitle(title))
        {
            loc = i;
            break;
        }
}

void searchBookData(bookType books[], int bookCount)
{
    int choice;
    char ch;
    int loc;
    string str;

    subMenu();

    cin >> choice;
    cin.get(ch);

    switch(choice)
    {
	case 1:
        cout << "Enter the ISBN of the book." << endl;
        getline(cin, str);
        searchBookDataByISBN(books, bookCount, str, loc);
        if (loc != -1)
            cout << "The store sells this book." << endl;
        else
            cout << "The store does not sell this book" << endl;
        break;
	case 2:
        cout << "Enter the title of the book." << endl;
        getline(cin, str);
        searchBookDataByTitle(books, bookCount, str, loc);
        if (loc != -1)
            cout << "The store sells this book." << endl;
        else
            cout << "The store does not sell this book" << endl;
        break;
	default:
        cout << "Invalid choice" << endl;
    }
}

void updateCopiesInStock(bookType books[], int bookCount)
{
    int choice;
    int loc;
    int count;
    char ch;

    string str;

    subMenu();
    cin >> choice;
    cin.get(ch);

    switch (choice)
    {
	case 1:
        cout << "Enter the ISBN of the book." << endl;
        getline(cin, str);
        searchBookDataByISBN(books, bookCount, str, loc);
        if (loc != -1)
        {
            cout << "Enter the number of books: " ;
            cin >> count;
            cout << endl;

            books[loc].updateQuantity(count);
        }
        else
            cout << "The store does not sell this book: " << endl;
        break;
	case 2:
        cout << "Enter the title of the book." << endl;
        getline(cin, str);
        searchBookDataByTitle(books, bookCount, str, loc);
        if (loc != -1)
        {
            cout << "Enter the number of books" ;
            cin >> count;
            cout << endl;

            books[loc].updateQuantity(count);
        }
        else
            cout << "The store does not sell this book" << endl;
        break;
	default:
        cout << "Invalid choice" << endl;
	}
}

void showMenu()
{
    cout << "\nWelcome to Buffalo State Book Store" << endl;
    cout << "***********************************" << endl;
    cout << "To make a selection enter the number and press enter" << endl;
    cout << "1:  Print a list of books" << endl;
    cout << "2:  Print a list of books and ISBN numbers" << endl;
    cout << "3:  To see if a book in store" << endl;
    cout << "4:  To update the number of copies of a book" << endl;
    cout << "5:  To print books data" << endl;
    cout << "9:  Exit the program." << endl;
}

void subMenu()
{
    cout << "Enter" << endl;
    cout << "1: To search the book by ISBN" << endl;
    cout << "2: To search the book by title" << endl;
}
