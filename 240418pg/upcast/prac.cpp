#include <iostream>
using namespace std;

class Person {
public:
    void speak() {};
    void eat() {};
    void walk() {};
    void sleep() {};

};

class Student : public Person {
public:
    void study() {};
};

class Researcher : public Person {
public:
    void Research() {};
};

class Professor : public Researcher {
public:
    void teach() {};
};

int main() {
    Person *p[4] = {new Person(), new Student(), new Researcher(), new Professor()};

    for (int i = 0; i < 4; i++) {
        p[i]->eat();
        p[i]->sleep();
    }

    ((Professor*)p[3])->teach();
    //((Professor*)p[2])->teach();
}