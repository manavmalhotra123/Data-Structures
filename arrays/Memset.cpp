// changing the values of whole character array using memset function 
// C++ program to demonstrate memset
#include <cstring>
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	char str[] = "geeksforgeeks";
	memset(str, 't', sizeof(str));
	cout << str;
	return 0;
}
