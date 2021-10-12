#include <iostream>
#include <sstream>
#include <iomanip>
#include <winsock.h>
#include <cstdlib>
#include <mysql.h>
#include <windows.h>
#include "BankAccount.h"
#include "BankTransaction.h"

using namespace std;


enum Options { PRINT = 1, NEW, WITHDRAW, DEPOSIT,
               CLOSE, END };

int mainMenu()
{
     int ch;
   cout << "\nMenu Options" << endl
        << "1 - Print All Account"
        << endl << "2 - Open New Account" << endl
        << "3 - Withdraw" << endl << "4 - Deposit"
        << endl << "5 - Close Account" << endl
        << "6 - End Transaction" << endl;

   cin >> ch;
   return ch;
}

int main(int argc, char** argv)
{
   BankTransaction* bt =
      new BankTransaction("127.0.0.1", "root","","bankofxo");

   int choice;
   int acno;
   string fname, lname;
   double bal;

   while(1) {
      choice = mainMenu();
      if(choice == END)
         break;
      switch(choice) {
      case PRINT:
         bt->printAllAccounts();
         break;
      case NEW:
         cout << "\nEnter the account no:"
              << endl;
         cin >> acno;
         cout<<"\nEnter the First Name of the Account Holder"<<endl;
         cin >> fname;
          cout<<"\nEnter the Last Name of the Account Holder"<<endl;
         cin >> lname;
         cout<<"\nInsert Opening Amount"<<endl;
         cin >> bal;
         if(acno < 1) {
            cout << "Invalid account number." << endl;
            break;
         }
         bt->createAccount(new BankAccount(acno, fname, lname,bal));
         break;
      case WITHDRAW:
         cout << "\nEnter account no:"<<endl;
         cin >> acno;
             cout<<"\n Enter amount to withdraw: "<<endl;
        cin >> bal;
         if(bal < 0) {
            cout << "Invalid amount." << endl;
            break;
         }

         bt->withdraw(acno, bal);
         break;
      case DEPOSIT:
         cout << "\nEnter account no:"<<endl;
           cin >> acno;
         cout <<"Enter amount to deposit :"<<endl;
        cin >> bal;
         if(bal < 0) {
            cout << "Invalid amount." << endl;
            break;
         }
         bt->deposit(acno, bal);
         break;
     case CLOSE:
         cout << "\nEnter account no to close account "<<endl;
         cin >> acno;
         bt->closeAccount(acno);
         break;
      default:
         cerr << "Invalid choice!" << endl;
         break;
      }
   }
   return 0;
}
