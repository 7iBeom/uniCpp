#include <stdio.h>

typedef struct student {
    char name[20];
    char num[10];
    int kor, eng, math;
}STUDENT;

STUDENT Input(STUDENT *p, int c) {
    printf("name: "); scanf("%s", (p+c)->name);
    printf("number: "); scanf("%s", (p+c)->num);
    printf("korean: "); scanf("%d", &(p+c)->kor);
    printf("english: "); scanf("%d", &(p+c)->eng);
    printf("math: "); scanf("%d", &(p+c)->math);
    printf("Registration is complete\n");

    return *p;
}

char getGrade(int k, int e, int m) {
    int avg = (k + e + m) / 3;
    if(avg >= 90) return 'A';
    else if(avg >= 80) return 'B';
    else if(avg >= 70) return 'C';
    else if(avg >= 60) return 'D';
    else return 'F';
}

void Output(STUDENT info[], int c) {
    printf("%s의 성적\n", info[c].name);
    printf("Korean: %d English: %d Math: %d Grade: %c\n", info[c].kor, info[c].eng, info[c].math, 
    getGrade(info[c].kor, info[c].eng, info[c].math));
}

int main() {
    STUDENT s[100];
    int cnt = 0;
    int sel = 0;

    while(sel != 3) {
        printf("1. input 2. output 3. exit\nSelect the menu: ");
        scanf("%d", &sel);

        switch(sel) {
            case 1: Input(s, cnt); cnt++; break;
            case 2: 
                for(int i = 0; i < cnt; i++) Output(s, i);
                break;
            case 3: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    }
    
    return 0;
}