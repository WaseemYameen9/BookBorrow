#include<iostream>
#include<fstream>
using namespace std;

/*---------------Structures----------------*/
struct borrower
{
    string borrowerName;
    string address;
    string contact;
    string borrowedBookName;
} ;
struct borrower borrowerList[10];
int borrowerCounter;
struct Book
{
    string title;
    string author;
    int isbn;
    int noOfCopies;
    int noOfCopiesOut;
};
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
    cout << "                          *ADMIN*       " << endl;
    cout << "                         *MAIN MENU*           " << endl;
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
        cout << "                         *LOGIN PAGE*       " << endl;
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

void printAvaliableBooksList(){
    cout<< "Borrower Name - Address - Contact - Book Borrow"<<endl;
    int y=1;
    for (auto &&i : BookList)
    {
        if(i.title==""){
            return;
        }
        cout<<y<<" - "<<i.title<<" - "<<i.author<<" - "<<i.isbn<<" - "<<i.noOfCopies<<" - "<<i.noOfCopiesOut<<endl;
        y++;
    }
}

void printBorrowers(){
    cout<< "Borrower Name - Address - Contact"<<endl;
    int y=1;
    for (auto &&i : borrowerList)
    {
        if(i.borrowerName==""){
            return;
        }
        cout<<y<<" - "<<i.borrowerName<<" - "<<i.address<<" - "<<i.contact<<endl;
        y++;
    }
}
void addNewBorrower(string name,string address,string contact, string bookName){
    borrowerList[borrowerCounter].borrowerName=name;
    borrowerList[borrowerCounter].address=address;
    borrowerList[borrowerCounter].borrowedBookName=bookName;
    borrowerList[borrowerCounter].contact=contact;
    borrowerCounter++;
}
void printBookedBorrowerLst(){
    cout<< "Borrower Name - Address - Contact - Book Borrow"<<endl;
    int y=1;
    for (auto &&i : borrowerList)
    {
        if(i.borrowerName==""){
            return;
        }
        if(i.borrowedBookName!=""){
            cout<<y<<" - "<<i.borrowerName<<" - "<<i.address<<" - "<<i.contact<<" - "<<i.borrowedBookName<<endl;
        }
        y++;
    }
}
void returnFromBorrower(string name){
    for (int i=0;i<borrowerCounter;i++)
    {
        if(borrowerList[i].borrowerName==name){
            borrowerList[i].borrowedBookName="";
            break;
        }
    }
}
int getInput(int lowerLimit,int upperLimit){
    int x=0;
    while (cin>>x)
    {
        if(x>lowerLimit && x< upperLimit){
            return x;
        }
    }
    
}
string getStringInput(string Message){
    cout<<Message;
    string x="a";
    while (true)
    {
        cin>>x;
        if(x!=""){
            return x;
        }
    }    
}
int getIntInput(string Message){
    cout<<Message;
    int x=0;
    while (true)
    {
        try
        {
            cin>>x;
            if(x>0){
                return x;
            }
            /* code */
        }
        catch(const std::exception& e)
        {
            cout<<"Wrong Input"<<endl;
            continue;;
        }
    }
}
/**-------------------File Handling------------------*/
void StoreBook()
{
    int g = 0;
    fstream newfile;
    newfile.open("Bookdata.txt", ios::out);
    while (g <= bookCounter )
    {
        newfile << BookList[g].title << "," << BookList[g].author << "," << BookList[g].isbn << "," << BookList[g].noOfCopies << "," << BookList[g].noOfCopiesOut<< endl;
        g = g + 1;
    }
    newfile.close();
}
string recordget(string line, int field)
{
    string rec;
    int idxx = 0;
    int comaacount = 1;
    while (line[idxx] != '\0')
    {
        if (line[idxx] == ',')
        {
            comaacount = comaacount + 1;
        }
        else if (comaacount == field)
        {
            rec = rec + line[idxx];
        }
        idxx = idxx + 1;
    }
    return rec;
}
void loadBook()
{
    string line;
    fstream newwfile;
    newwfile.open("Bookdata.txt", ios::in);
    while (!newwfile.eof())
    {
        getline(newwfile, line);
        if (line == "")
        {
            break;
        }
        else
        {
            BookList[bookCounter].title = recordget(line, 1);
            BookList[bookCounter].author = stoi(recordget(line, 2));
            BookList[bookCounter].isbn = stoi(recordget(line, 3));
            BookList[bookCounter].noOfCopies = stoi(recordget(line, 4));
            BookList[bookCounter].noOfCopiesOut = stoi(recordget(line, 5));
            bookCounter = bookCounter + 1;
        }
    }
    newwfile.close();
}
/**--------------Store Borrower------------------------------------*/
void StoreBorrower()
{
    int g = 0;
    fstream newfile;
    newfile.open("Borrowerdata.txt", ios::out);
    while (g <= borrowerCounter )
    {
        newfile << borrowerList[g].borrowerName << "," << borrowerList[g].address << "," << borrowerList[g].contact << "," << borrowerList[g].borrowedBookName << endl;
        g = g + 1;
    }
    newfile.close();
}
string recordget2(string line, int field)
{
    string rec;
    int idxx = 0;
    int comaacount = 1;
    while (line[idxx] != '\0')
    {
        if (line[idxx] == ',')
        {
            comaacount = comaacount + 1;
        }
        else if (comaacount == field)
        {
            rec = rec + line[idxx];
        }
        idxx = idxx + 1;
    }
    return rec;
}
void loadBorrower()
{
    string line;
    fstream newwfile;
    newwfile.open("Borrowerdata.txt", ios::in);
    while (!newwfile.eof())
    {
        getline(newwfile, line);
        if (line == "")
        {
            break;
        }
        else
        {
            borrowerList[borrowerCounter].borrowerName = recordget2(line, 1);
            borrowerList[borrowerCounter].address = stoi(recordget2(line, 2));
            borrowerList[borrowerCounter].contact = stoi(recordget2(line, 3));
            borrowerList[borrowerCounter].borrowedBookName = stoi(recordget2(line, 4));
            borrowerCounter = borrowerCounter + 1;
        }
    }
    newwfile.close();
}
main()
{
    loadBook();
    loadBorrower();
    p:
    Login();
    string misc;
    int op = 1;
    while (op <= 7)
    {
        //loadBook();
        //loadBorrower();
        system("CLS");
        op = MainMenu();
        if (op == 1)
        {
            string borrowerName;
            string address;
            string contact;
            string borrowedBookName;
            cout<<"Enter Borrower's Name : ";
            cin>>borrowerName;
            cout<<"Enter Borrower's Address :";
            cin>>address;
            cout<<"Enter Borrower's Contact :";
            cin>>contact;
            
            cout<<"Enter Book Name :";
            cin>>borrowedBookName;
            addNewBorrower(borrowerName,address,contact,borrowedBookName);
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;
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
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;
        }

        if (op == 3)
        {
            printBorrowers();
            cout<<"Select Any one Burrower :";
            int index;
            cin>>index;
            index--;
            //&& 
            if(index < borrowerCounter and borrowerList[index-1].borrowedBookName==""){
                printAvaliableBooksList();
                cout<<"Select reqiured Book :";
                int bookIndex;
                cin>>bookIndex;
                if(bookIndex < bookCounter && BookList[bookIndex-1].noOfCopies > 0){
                    borrowerList[index-1].borrowerName = BookList[bookIndex-1].title;
                }
                else{
                    cout<<" Not Available ";
                }    
            }
            else{
                continue;
            }
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;
        }

        if (op == 4)
        {
            printBookedBorrowerLst();
            int index=0;
            cout<<"Select the Borrower :";
            cin>> index;
            returnFromBorrower(borrowerList[index-1].borrowerName);  
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;        
        }

        if (op == 5)
        {
            printAvaliableBooksList();
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;
        }
        if (op == 6)
        {
            printBorrowers();
            cout<<"Press Any numeric Key to Continue .........";
            cin>>misc;
        }

        if (op == 7)
        {
            /*  Logout  */
            StoreBook();
            StoreBorrower();
            system("CLS"); 
            goto p;
        }
       
        system("CLS");  
    }
}