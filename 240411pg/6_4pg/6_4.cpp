#include <iostream>
#include <string>

using namespace std;

void a(char sym = ' ', int line = 1);

void a(char sym, int line) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < 10; j++) {
            cout << sym;
        }
        cout << endl;
    }
}

int main() {
    a();
    a('*');
    a('%', 5);
    return 0;
}