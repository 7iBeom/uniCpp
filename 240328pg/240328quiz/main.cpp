#include <iostream>
#include <string>
using namespace std;

#include "WordCount.h"

int findIndex(WordCount *w[], int countIdx, string foundStr) {
    for (int i = 0; i < countIdx; i++) {
        if (w[i]->equalStr(foundStr)) {
            w[i]->increase();
            return 1;
            break;
        }
    } 
    return 0;
}

string strReplace(string &foundStr, int &countWord) {
    for (int i = 0; i < countWord; i++) {
        if ()
    }
    foundStr.find(f, )
}

int main() {
    string s = "I Love C++ I Hate Python Hello C++ C++";
    int countIdx = 0; // 문자열 카운트
    WordCount *w[100]={nullptr}; // 문자와 카운트를 저장하는 포인터 배열
    int startIdx = 0; // 시작 위치 저장

    while(true) {
        int foundIdx = s.find(' ', startIdx); // 문자열의 시작부터 ' '를 발견할 때 까지
        int countWord = foundIdx - startIdx; // ' '가 발견된 인덱스에서 처음 인덱스를 빼기
        string foundStr = s.substr(startIdx, countWord); // 발견
        
        w[countIdx] = new WordCount(foundStr, 1);

        if(!findIndex(&(*w), countIdx, foundStr))
            countIdx++;
        else 
            delete w[countIdx];

        startIdx = foundIdx + 1;

        if (foundIdx == -1) // 문장의 끝이라면 반복문 종료
            break;
    }

    for (int i = 0; i < countIdx; i++) {
        w[i]->show();
        delete w[i];
    }

    return 0;
}