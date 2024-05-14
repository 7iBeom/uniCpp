#include <iostream>
#include <string>
#include "accClass.h"

using namespace std;

int main() {
    Account acc1("12341234", "kkb", 10000, "0000");
    acc1.deposit(10000);

    acc1.withdraw(15000, "0000");

    Account acc2("11223344", "abc", 10000, "0001");

    acc1.transfer(2000, "0000", &acc2);
}