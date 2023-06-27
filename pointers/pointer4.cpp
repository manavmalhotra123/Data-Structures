#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5; // block that contains the value 5
    int* b = &a; // pointer that points to the variable a , contains the address of the variable a
    int** c = &b; // pointer to pointer

    cout<<&a<<endl; // address of the variable a
    cout<<a<<endl;  // value of a 
    cout<<b<<endl;  // address of the variable a
    cout<<&b<<endl; // address of the variable b
    cout<<*b<<endl; // value at a 
    cout<<c<<endl; // address of variable b
    cout<<&c<<endl; // address of the variable c
    cout<<*c<<endl; // value stored in variable b which is basically the address of the variable a 
    cout<<**c<<endl; // pehle c mai jo value (address) store hai us variable pr jayo then jo value(address) b mai store hai uski value pr jaayo 
    // in short print krde value a ki 
    return 0;
}
