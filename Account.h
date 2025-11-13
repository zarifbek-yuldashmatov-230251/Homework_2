#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
string ownerName;
double balance;
public:
Account (string name, double blnc) {
ownerName=name;
balance=blnc;
}
double getBalance() {
return balance;
}
virtual void display() {
cout<<"Owner: "<<ownerName<<endl;
cout<<"Balance: "<<balance<<endl;
}
virtual ~Account () {
    cout<<"Account closed for "<<ownername<<endl;
}
};

class SavingsAccount: public Account {
private:
double interestRate;
public: 
SavingsAccount (string n, double b, double intrate):Account (string ownername, double balance){
interestRate=intrate;
}
void display() override {
    Account.display();
cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
}
};

class CheckingAccount: public Account {
private:
double transactionFee;
public: 
CheckingAccount (string n, double b, double transfee):Account (string ownername, double balance){
transactionFee=transfee;
}
void display() {
Account.display();
    cout<<"Transaction Fee: " <<transactionFee<<endl;
}
};
#endif
