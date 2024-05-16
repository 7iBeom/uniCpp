#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> storage;
    map<string, int>::iterator it;
    string prod;
    int cnt;
    int sel = 0;
    while  (sel != 4) {
        cout << "1. 입고 2. 출고 3. 재고현황 4. 종료: ";
        cin >> sel;
        switch(sel) {
            case 1:
                cout << "입고처리" << endl;
                cout << "제품명: "; cin >> prod;
                cout << "수량: "; cin >> cnt;
                if (storage.find(prod) == storage.end()) 
                    storage[prod] += cnt;
                else 
                    storage[prod] += cnt;
                break;
            case 2:
                cout << "출고처리" << endl;
                cout << "제품명: "; cin >> prod;
                cout << "수량: "; cin >> cnt;
                for (it = storage.begin(); it != storage.end(); it++) {
                    if (prod == it->first && it->second > 0 && it->second >= cnt) {
                        it->second -= cnt;
                        cout << it->first << ":" << it->second << endl;
                    }
                    else 
                        cout << "출고 실패" << endl;
                }
                break;
            case 3:
                cout << "재고 현황 확인" << endl;
                for (it = storage.begin(); it != storage.end(); it++) {
                    cout << it->first << ":" << it->second << endl;
                }
                break;
            case 4:
                cout << "종료" << endl;
                break;
            default:
                break;
        }
    }
    
}