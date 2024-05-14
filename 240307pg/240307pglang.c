#include<stdio.h>

int main() {
    int a = 10;
    int * ptr = &a;
    int ** d_ptr = &ptr;

    printf("1. value of a: %d\n 1.1 address of a: %p\n", a, &a);

    printf("2. value pointed to single pointer ptr: %d\n 2.1 value of single pointer ptr: %p\n 2.2 address of single pointer ptr: %p\n",*ptr, ptr, &ptr);

    printf("3. pointer to a pointer of double pointer d_ptr: %d\n 3.1 pointer of double pointer d_ptr: %p\n 3.2 value of double pointer d_ptr: %p\n 3.3 address of double pointer d_ptr: %p\n",**d_ptr, *d_ptr, d_ptr, &d_ptr);

    return 0;

}