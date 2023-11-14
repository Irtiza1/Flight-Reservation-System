#ifndef CLASS_BANK_ACCOUNT_H
#define CLASS_BANK_ACCOUNT_H
#include<iostream>
#include <string>
using namespace std;
class Bank_account{
private:
int balance;
public:
Bank_account(){
    balance = 0;
}
Bank_account(int b){
    balance = b;
}
void set_balance(int b){
    balance = b;
}
int get_balance(){
    return balance;
}
void debit(){
    print_details();
    int amount;
    cout<<"Enter amount to be debited\n";
    cin>>amount;
    balance = balance + amount;
}
void credit(){
    print_details();
    int amount;
    cout<<"Enter amount to be credited\n";
    cin>>amount;
    if(amount > balance){
        cout<<"Insufficent Balance\n";
        return;
    }    
    balance = balance - amount;
}
void transaction(){
    int ch;
    cout<<"Choose operation:\n1.Debit\t2.Credit\n";
    cin>>ch;
    if(ch == 1){
        debit();
    }
    else if(ch == 2){
        credit();
    }
    else{
        cout<<"Invalid choice\n";
    }
}
void print_details(){
    cout<<"Current Balance: "<<balance<<endl;
}
};

#endif
