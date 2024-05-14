#include <iostream>
#include <string>
using namespace std;

class WordCount {
    string word;
    int cnt;
public:
    WordCount(string word, int cnt) {this->word = word; this->cnt = cnt; };
    void increase() {cnt++;}
    int equalStr(string word) {return this->word == word;} // 나온적이 있는 문자열인가를 확인하는 함수
    void show() {cout << word << ": " << cnt << endl;} // 배열 출력 함수
};

