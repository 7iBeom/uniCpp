// 22213487 권기범
// Account class
#include <string>
using namespace std;

class Account {
    string accNum; // 계좌번호
    string accOwner; // 예금주
    int accBal; // 잔액
    string accPw; // 비밀번호
public:
    Account(string, string, int, string);
    void deposit(int); // 입금
    int withdraw(int, string); // 출금
    int transfer(int, string, Account*); // 송금
    void showBal(string); // 잔액조회
    int equalAccno(string); // 로그인 기능 함수 
    string getOwner(); // 계좌주 확인 함수
    int checkPw(string); // 비밀번호 확인 함수
};