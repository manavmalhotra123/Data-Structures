#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5; // int space is allocated in the memory
    // but to refer it we need to access it through the address at which the space is allocated

    // symbol table is the table in which the storage is done for the variable name and the address of the variable
    cout << a << endl;

    // printing the address of the variable where a is allocated
    cout << &a << endl; // stored in hexadecimal format

    bool b = 5;
    cout << b << endl;
    cout << &b << endl;


    // pointer ek aisa data-type hai jo ki sirf address ko store krta hai 
    // int* is the pointer to integer data
    int* ptr = &a;   // storing  the address of the variable in ptr vairiable
    cout<<ptr<<endl; // will print the address of the variable a
    cout<<ptr+1 << endl; // will print the address of the variable
    cout<<*ptr<<endl; // will print the value of the variable that is allocated to the variable

    // * is the dereference operator
    // size of the pointer is always 8 (architecture dependent)


    // NULL pointer 
    int* p = 0;
    int* v = NULL;
    return 0;
}
