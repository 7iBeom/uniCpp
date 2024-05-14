// 22213487 권기범
#include <iostream>
#include <string>
#include "22213487accClass.h"

using namespace std;

int findindex(Account* acc, int cnt, string accno) {
    for (int i = 0; i < cnt; i++) {
        if (acc[i].equalAccno(accno)) {
            return i;
        }
    } 
    cout << "잘못된 계좌번호" << endl;
    return -1;
}

int main() {
    Account acc[] = {
        Account("1234-1234", "kim", 10000, "1234"),
        Account("5678-5678", "lee", 20000, "0000"),
        Account("1212-1212", "park", 30000, "0101")
    };
    int cnt = 3;

    while(1) {
        string accNo, transAcc;
        cout << "계좌번호 입력: "; cin >> accNo;
        int userIdx = findindex(acc, cnt, accNo);
        if (userIdx == -1) continue;
        int sel = 0, amount = 0;
        string pw;
        cout << acc[userIdx].getOwner() << "님 환영합니다" << endl;
        while (sel != 5) {
            cout << "1. 입급 2. 출금 3. 송금 4. 조회 5. 종료 : ";
            cin >> sel;
            switch(sel) {
                case 1:
                    cout << "입금액 : "; cin >> amount;
                    acc[userIdx].deposit(amount);
                    cout << "입금되었습니다." << endl;
                    break;
                case 2: 
                    cout << "비밀번호 입력: "; cin >> pw;
                    if(acc[userIdx].checkPw(pw)) {
                        cout << "출금액: "; cin >> amount;
                    }
                    acc[userIdx].withdraw(amount, pw);
                    break;
                case 3: 
                    cout << "비밀번호 입력: "; cin >> pw;
                    cout << "송금할 계좌번호 입력: "; cin >> transAcc;
                    if(acc[userIdx].checkPw(pw)) {
                        cout << "송금액: "; cin >> amount;
                    }
                    acc[userIdx].transfer(amount, pw, &acc[findindex(acc, cnt, transAcc)]);
                    break;
                case 4:
                    cout << "비밀번호 입력: "; cin >> pw;
                    acc[userIdx].showBal(pw); 
                    break;
                case 5:
                    cout << "안녕히 가세요" << endl; 
                    break;
                default:;
            }
        }
    }
    return 0;
}