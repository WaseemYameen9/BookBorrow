#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int i = 0, q = 0;
int counnt = 0;
string stuname[10] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
int matric[10];
int inter[10];
int rollnum[10];
int classes[10];
int aclases[10];
float percentage[10];
string teanames[10];
string teadepart[10];
string post[10];
int teasalary[10];
int fee[10];
string duedate[10] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
int fatherinc[10];
string need[10];
float attenpercent[10];
string newname[10];
string namee, namee1, namee2, namee3, namee4;
void header()
{
   cout<<"--------------------------------------"<<end;
   cout<<"|        Books Borrowing System       |"<<end;
   cout<<"--------------------------------------"<<end;
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
    cout << "enter your option:";
    cin >> option;
    return option;
}
 /* void save()
{
    int g = 0;
    fstream newfile;
    newfile.open("data.txt", ios::out);
    while (g < i)
    {
        newfile << stuname[g] << "," << matric[g] << "," << rollnum[g] << "," << aclases[g] << "," << fee[g] << "," << percentage[g] << "," << attenpercent[g] << "," << duedate[g] << "," << teanames[g] << "," << teadepart[g] << "," << post[g] << "," << teasalary[g] << endl;
        g = g + 1;
    }
    newfile.close();
}
void load()
{
    string line, matrics, rollnums, aclasess, fees;
    fstream newwfile;
    newwfile.open("data.txt", ios::in);
    while (!newwfile.eof())
    {
        getline(newwfile, line);
        if (line == "")
        {
            break;
        }
        else
        {
            stuname[counnt] = recordget(line, 1);
            matric[counnt] = stoi(recordget(line, 2));
            rollnum[counnt] = stoi(recordget(line, 3));
            aclases[counnt] = stoi(recordget(line, 4));
            fee[counnt] = stoi(recordget(line, 5));
            percentage[counnt] = stof(recordget(line, 6));
            attenpercent[counnt] = stof(recordget(line, 7));
            duedate[counnt] = recordget(line, 8);
            teanames[counnt] = recordget(line, 9);
            teadepart[counnt] = recordget(line, 10);
            post[counnt] = recordget(line, 11);
            teasalary[counnt] = stoi(recordget(line, 12));
            counnt = counnt + 1;
        }
    }
    newwfile.close();
}
*/
main()
{
    i = counnt;
    string username, password;
    int option = 1;
    while (option <= 2)
    {
        header();
        cout << "                          ***LOGIN PAGE***       " << endl;
        cout << "              ________________________________________" << endl;
        cout << "1- admin" << endl;
        cout << "2- student" << endl;
        cout << "3- exit" << endl;
        cout << "enter your option:";
        cin >> option;
        system("CLS");

        if (option == 1)
        {
            while (true)
            {
                header();
                cout << "                          ***LOGIN PAGE***       " << endl;
                cout << "                           ***ADMIN***           " << endl;
                cout << "-------Username must include '@' character-----" << endl;
                cout << "enter username:";
                cin >> username;
                cout << "enter password(in digits):";
                cin >> password;
                system("CLS");
            }
            int op = 1;
            while (op <= 7)
            {
                system("CLS");
                op = admenu();
                if (op == 1)
                {
                   
                if (op == 2)
                {
                   
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
                   
                }
            }
            system("CLS");
        }

        if (option == 2)
        {
            int op1;
            while (true)
            {
                op1 = 1;
                header();
                cout << "                          ***LOGIN PAGE***       " << endl;
                cout << "                           ***STUDENT***           " << endl;
                cout << "----------Username must include '@'---------" << endl;
                cout << "enter username:";
                cin >> username;
                cout << "enter password(in digits):";
                cin >> password;
                system("CLS");
            }
            while (op1 <= 4)
            {
                system("CLS");
                op1 = stumenu();

                if (op1 == 1)
                {
                   
                }
                if (op1 == 2)
                {
                   
                }
                if (op1 == 3)
                {
                 
                }
                if (op1 == 4)
                {
                 
                }
            }
            system("CLS");
        }
        if (option == 3)
        {
            
            header();
            cout << "------------------------------------------------------" << endl;
            cout << "-------------- POWERED BY WASEEM  2021-CS-61----------" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "THANK YOU FOR USING CMS" << endl;
            cout << "GOOD BY" << endl;
            
        }
    }
}
}