#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5; // int space is allocated in the memory 
    // but to refer it we need to access it through the address at which the space is allocated



    // symbol table is the table in which the storage is done for the variable name and the address of the variable
    cout << a << endl;

    cout<< &a << endl;
    return 0;
}
