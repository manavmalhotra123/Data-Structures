#include<iostream>
#include<string>

using namespace std;

void find_using_recursion(string &s, char c,int i){
    
    // if length of the string is parsed then stop
    if (i >= s.length()) 
    {
        return;
    }

    // code for single case
    if (s[i] == c) 
    {
        cout<<"found at index "<<i<<endl;
    }
    
    // baaki recurssion to dekhne de bhai
    find_using_recursion(s,c,i+1);
    
}


int main(int argc, char const *argv[])
{
    string s = "Anmol";
    char c = 'o';
    int index = 0;

    find_using_recursion(s,c,index);




    return 0;
}
