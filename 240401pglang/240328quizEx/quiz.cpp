#include<string>
#include<iostream>
using namespace std;

class Wordcnt {
	string word;
	int cnt;
public:
	Wordcnt(string word, int cnt) { this->word = word; this->cnt = cnt; }
	void increase() { cnt++; }
	int equalString(string word) { return this->word == word; }
	void show() { cout << word << " : " << cnt << endl; }
};

int findIndex(Wordcnt* w[100], int cnt, string word)
{
	for (int i = 0; i < cnt; i++)
	{
		if (w[i]->equalString(word))
			return i;
	}
	return -1;
}


void myupper(string &str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}
void myreplace(string &str, string f, string r)
{
	int startIndex = 0;
	while (true) {
		int fIndex = str.find(f, startIndex); // startIndex부터 문자열 f 검색
		if (fIndex == -1)
			break; // 문자열 s의 끝까지 변경하였음
		str.replace(fIndex, f.length(), r); // fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
		startIndex = fIndex + r.length();
	}
}

int main()
{
	Wordcnt* w[100]; // 단어를 저장할 포인터 배열 
	int cnt = 0; // 몇종류의 단어가 저장되었는지.
	string s = "I-Love c++,i Hate Python Hello pythoN C++";
	myreplace(s, "-", " ");
	myreplace(s, ",", " ");
	myupper(s);
	int startIndex = 0;

	while (true) {
		int fIndex = s.find(' ', startIndex);
		if (fIndex == -1) { // '+' 문자 발견할 수 없음
			string part = s.substr(startIndex);
			int idx = findIndex(w, cnt, part);
			if (idx < 0)
				w[cnt++] = new Wordcnt(part, 1);
			else
				w[idx]->increase();
			break;
		}
		int count = fIndex - startIndex; // 서브스트링으로 자를 문자 개수
		string part = s.substr(startIndex, count); // startIndex부터 count 개의 문자로 서브스트링 만들기
		
		int idx = findIndex(w, cnt, part); // w배열에 part가 어디에 있는지?
		if (idx < 0)
			w[cnt++] = new Wordcnt(part, 1); //idx가 음수이므로 part는 처음 등장
		else
			w[idx]->increase(); // part는 idx에 존재하고 idx위치에 있는 단어를 증가

		startIndex = fIndex + 1; // 검색을 시작할 인덱스 전진시킴
	}
	for (int i = 0; i < cnt; i++)
	{
		w[i]->show();
	}
}