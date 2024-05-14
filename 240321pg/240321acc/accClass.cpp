#include <iostream>
#include <string>
using namespace std;

#include "accClass.h"

Account::Account(string num, string name, int bal, string pw) {
    accNum = num;
    accOwner = name;
    accBal = bal;
    accPw = pw;
}

void Account::deposit(int amount) {
    if (amount <= 0) return;
    accBal += amount;
    showBal();
}

int Account::withdraw(int amount, string ptrPw) {
    if (amount <= 0) return 0;
    if (accPw != ptrPw) return 0;
    accBal -= amount;
    showBal();

    return 1;
}

int Account::transfer(int amount, string ptrPw, Account* acc) {
    if (!withdraw(amount, ptrPw)) return 0;
    acc->deposit(amount);

    return 1;
}

void Account::showBal() {
    cout << accOwner <<"의 잔액: " << accBal <<"원" << endl;
}