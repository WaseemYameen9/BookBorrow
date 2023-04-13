#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/*---------------Structures----------------*/
struct Book
{
    string title;
    string author;
    string isbn;
    string noOfCopies;
} ;
struct Book BookList[10];
int bookCounter;

/*-----------------------Functions----------------*/


void header()
{
   cout<<"--------------------------------------"<<endl;
   cout<<"|        Books Borrowing System       |"<<endl;
   cout<<"--------------------------------------"<<endl;
}
int MainMenu()
{
    int option;
    header();
    cout << "                          ***ADMIN***       " << endl;
    cout << "                         ***MAIN MENU***           " << endl;
    cout << "1- Add Borrower" << endl;
    cout << "2- Add Book" << endl;
    cout << "3- Borrow a Book" << endl;
    cout << "4- Return a Book" << endl;
    cout << "5- View Books Information" << endl;
    cout << "6- View Borrowers Information" << endl;
    cout << "7- Logout" << endl;
    cout << "enter your option:";
    cin >> option;
    return option;
}

bool Login()
{
    string username, password;
    while (true)
    {
        system("cls");
        header();
        cout << "                         ***LOGIN PAGE***       " << endl;
        cout << "-------Enter Username and Password to Login-----" << endl;
        cout << "enter username:";
        cin >> username;
        cout << "enter password(in digits):";
        cin >> password;
        if(username=="admin" and password=="123")
        {
            return true;
        }
    }
}

void addNewBook(string name,string author,int isbn, int noOfCopies){
    BookList[bookCounter].title=name;
    BookList[bookCounter].author=author;
    BookList[bookCounter].isbn=isbn;
    BookList[bookCounter].noOfCopies=noOfCopies;
    bookCounter++;
}

/*------------------------Main-----------------------*/
main()
{
    Login();
    int op = 1;
    while (op <= 7)
    {
        system("CLS");
        op = MainMenu();
        if (op == 1)
        {

        }
                 
        if (op == 2)
        {
            string title,author;
            int isbn,noOfCopies;
            system("CLS");
            cout << "Enter Title:";
            cin >> title;
            cout << "Enter Author:";
            cin >> author;
            cout << "Enter ISBN:";
            cin >> isbn;
            cout << "Enter Number of copies:";
            cin >> noOfCopies;
            addNewBook(title,author,isbn,noOfCopies);
                  
        }

        if (op == 3)
        {
                   
        }

        if (op == 4)
        {
                   
        }

        if (op == 5)
        {
                   
        }
        if (op == 6)
        {
                   
        }

        if (op == 7)
        {
                /*  Logout  */
        }
    }
    system("CLS");  
}

