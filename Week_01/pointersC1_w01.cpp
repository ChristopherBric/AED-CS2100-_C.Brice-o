//Week 1 - Pointers 1

#include<iostream>
using namespace std;

int main(){
    int a = 123;
    int *p = &a;
    cout << p << endl;
    cout << *p << endl;
    return 0;
}