// map 영한 사전 만들기

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, string> dic;
    char select;

    cout << "저장된 단어 개수" << dic.size() << endl;

    string eng;
    while(true) {
        cout << "단어 검색>>";
        getline(cin, eng);
        if (eng == "exit")
            break;

        if (dic.find(eng) == dic.end()) {
            cout << "검색 불가" << endl;
            cout << "단어 추가 <y/n>";
            getchar(select)
        }
        else
            cout << dic[eng] << endl;
            
    }

    cout << "종료" << endl;
}