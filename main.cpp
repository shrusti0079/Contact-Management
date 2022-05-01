 //Including header files
#include<iostream>
#include<conio.h>
#include<windows.h>         //this is added for accessing stream and system
#include<fstream>
using namespace std;

//declaring  global variables

string fname, lname, phn_num;


//declaring all the functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    //variables
    short int choice;

    //first cleaning the stream
    system("cls");
    system("color 3D"); //this changes color
    system("color 5B"); //this changes color purple background- text-color light blue
    cout<<"\n\n\n\t\t\tCONTACT MANAGEMENT\n\n\n";

    while(1)
    {    cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                addContact();
                break;
          case 2:
                searchContact();
                break;
          case 3:
              help();
              break;
          case 4:
              self_exit();
              break;
          default:
            cout<<" \n\n\t INVALID INPUT !";
            cout<<"\n\tPress any key to Continue....";
            getch();
            main();

        }
    }

    return 0;
}

//defining functions

void self_exit(){

    system("cls");
    cout << "\n\n\n\tThanks for your visit\n\n\n\t" << endl;
    exit(1);
    // here we are using exit code one
}

void help(){
    cout << "\n\tThis is simple contact management system, which is a console-based application.";
    cout << "\n\tA Menu is shown, enter number according to the command you want to give.";
    cout << "\n\t1-->Is adding a contact in the contact file.";
    cout<<"\n\t2-->For searching a saved contact, using user input keyword, which may be present as first name or last name of the contact";
    cout << "\n\t3-->For showing info about this program";
    cout << "\n\t4-->For making an exit from the program";
    cout << "\n\tNote: The contacts saved here, will name saved in the contact file, unless one deletes it by opening the file.";
    cout << "\n\n\t\tHope This Helps\n\n";

    //we can add here information ok.
}

void addContact(){
    //opening file.
    ofstream phone("numbers.txt", ios::app);                //for writing.
    system("cls");

    cout << "\n\n\tEnter First Name: ";
    cin >> fname;
    cout << "\n\tEnter Last Name: ";
    cin >> lname;
    cout << "\n\tEnter 10-digit Phone Number: ";
    cin >> phn_num;

    if(check_digits(phn_num)==true)
    {
        if(check_numbers(phn_num)==true)
        {
            if(phone.is_open())
            {
               //if file is open
               phone << fname << " " << lname << " " << phn_num << endl;
               cout<<"\n\tContact Saved Successfully. ";
            }
            else{
                cout << "\n\tError Opening Files  !";
            }
        }
        else
        {
            cout<<"\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else{
        cout << "\n\tA Phone Number Must Contain 10-digits !";
    }
    phone.close();          //closing the file
}

void searchContact(){

    bool found=false;
    ifstream phone("numbers.txt");
    string keyword;
    cout << "\n\tEnter Name of Contact to Search: ";
    cin >> keyword;
    system("cls");
    while(phone >> fname >> lname >> phn_num)
    {
        if( keyword == fname || keyword == lname )
        {

            cout << "\n\n\tContact Details...";
            cout << "\n\n\tFirst Name:\t" << fname;
            cout << "\n\tLast Name:\t" << lname;
            cout << "\n\tPhone Number:\t" << phn_num << endl;
            found=true;
            //break;
            //that means it will the first saved number if the names are same.

        }
    }
    if(found==false)
    {
        cout << "\n\n\tNo such Contact Found\n\n";
    }

}

bool check_digits(string num)
{
    if(num.length()==10)
    {
        return true;
    }
    return false;
}

bool check_numbers(string num)
{   //cout << "Inside check numbers" << endl;
    bool check=true;
    //we will check if each is not number, if yes then make check as false and return.
    for(int i=0; i<num.length(); i++)
    {

        if(!(int(num[i])>=48 and int(num[i])<=57))
        {
            check=false;
            //cout << "A non-numeric is found!" << endl;
            break;
        }
    }
    return check;
}

