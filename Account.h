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
Account (string name = "", double blnc = 0.0) {
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
    cout<<"Account closed for "<<ownerName<<endl;
}

Account operator+(const Account &other) const {
return Account(ownerName, balance + other.balance);
}

double operator-(const Account &other) const {
    return balance - other.balance;
}

bool operator==(const Account &other) const {
    return balance == other.balance;
}

friend ostream &operator<<(ostream &out, const Account &a) {
    out << "Owner: " << a.ownerName << endl;
    out << "Balance: " << a.balance << endl;
    return out;}

friend istream &operator>>(istream &in, Account &a) {
in >> a.ownerName >> a.balance;
return in;
}

};

class SavingsAccount: public Account {
private:
double interestRate;
public: 
SavingsAccount (string n, double b, double intrate):Account (n, b){
interestRate=intrate;
}

void display() override {
    Account::display();
cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
}
};

class CheckingAccount: public Account {
private:
double transactionFee;
public: 
CheckingAccount (string n, double b, double transfee):Account (n, b){
transactionFee=transfee;
}
void display() override {
Account::display();
    cout<<"Transaction Fee: " <<transactionFee<<endl;
}
};


#endif
