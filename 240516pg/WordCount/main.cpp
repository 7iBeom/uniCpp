#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    
    map<string, int> w;
    map<string, int>::iterator it;
    string s = "I Love C++ I Hate Python Hello C++ C++";
    int countIdx = 0; // 문자열 카운트
    int startIdx = 0; // 시작 위치 저장
    int cnt = 0;

    int i = 0;
    while(true) {
        int foundIdx = s.find(' ', startIdx); // 문자열의 시작부터 ' '를 발견할 때 까지
        int countWord = foundIdx - startIdx; // ' '가 발견된 인덱스에서 처음 인덱스를 빼기
        string foundStr = s.substr(startIdx, countWord); // 발견

        if (w.find(foundStr) == w.end())
            w[foundStr] += 1;
        else 
            w[foundStr] += 1;
            
        if (foundIdx == -1) break;

        startIdx = foundIdx + 1;
    }

    for (it = w.begin(); it != w.end(); it++) {
            cout << it->first << ":" << it->second << endl;
        }


    return 0;
}