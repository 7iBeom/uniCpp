// 22213487 권기범
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
 
// 입금 함수
void Account::deposit(int amount) {
    if (amount <= 0) return;
    accBal += amount;
}

// 출금 함수
int Account::withdraw(int amount, string ptrPw) {
    if (amount <= 0) return 0;
    if (accPw != ptrPw) return 0;
    if (accBal - amount < 0) { // 잔액부족 조건문
        cout << "잔액이 부족합니다" << endl;
        return 0;
    }
    accBal -= amount;
    showBal(ptrPw);

    return 1;
}

// 송금 함수
int Account::transfer(int amount, string ptrPw, Account* acc) {
    if (!withdraw(amount, ptrPw)) return 0;
    acc->deposit(amount);

    return 1;
}

// 잔액 조회 함수
void Account::showBal(string ptrPw) {
    if (checkPw(ptrPw))
        cout << accOwner <<"의 잔액: " << accBal <<"원" << endl;
}

// 계좌번호 일치 확인 함수 (로그인 기능)
int Account::equalAccno(string accno) {
    return accNum == accno; 
}

// 로그인 후 계좌주 확인 함수
string Account::getOwner() {
    return accOwner;
}

// 출금, 송금, 잔액조회 비밀번호 확인 함수
int Account::checkPw(string ptrPw) {
    if (accPw != ptrPw)
    {
        cout << "비밀번호가 틀렸습니다." << endl;
        return 0;
    } 
    else return 1;
}