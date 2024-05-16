// 22213487 권기범
#include <iostream>
#include <string>
#include <map>
#include "accClass.h"

using namespace std;

int main() {
    map<string, Account*> acc;
    acc["1234-1234"] = new Account("1234-1234" , "kim", 10000, "1234");
    acc["5678-5678"] = new Account("5678-5678" , "lee", 20000, "1111");
    acc["1212-1212"] = new Account("1212-1212", "park", 30000, "0101");

    while(1) {
        string accNo, transAcc;
        cout << "계좌번호 입력: "; cin >> accNo;

        if (acc.find(accNo) == acc.end()) {
            cout << "잘못된 계좌번호" << endl;
            continue;
        }

        int sel = 0, amount = 0;
        string pw;
        cout << acc[accNo]->getOwner() << "님 환영합니다" << endl;
        while (sel != 5) {
            cout << "1. 입급 2. 출금 3. 송금 4. 조회 5. 종료 : ";
            cin >> sel;
            switch(sel) {
                case 1:
                    cout << "입금액 : "; cin >> amount;
                    acc[accNo]->deposit(amount);
                    cout << "입금되었습니다." << endl;
                    break;
                case 2: 
                    cout << "비밀번호 입력: "; cin >> pw;
                    if(acc[accNo]->checkPw(pw)) {
                        cout << "출금액: "; cin >> amount;
                    }
                    acc[accNo]->withdraw(amount, pw);
                    break;
                case 3: 
                    cout << "비밀번호 입력: "; cin >> pw;
                    if(acc[accNo]->checkPw(pw)) {
                        cout << "송금할 계좌번호 입력: "; cin >> transAcc;
                        cout << "송금액: "; cin >> amount;
                    }
                    acc[accNo]->transfer(amount, pw, acc[transAcc]);
                    break;
                case 4:
                    cout << "비밀번호 입력: "; cin >> pw;
                    acc[accNo]->showBal(pw); 
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