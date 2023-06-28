// inclusion - exclusion principle based question 

// print all the subsequences of the vector


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_sub_sequence(string &input,string output,int iterator){

    // base case -- jaise hi lenght khtm ho string ko print maardo baat khatam aur function end krdo woh instant ka 
    if (iterator == input.length())
    {
        // print the subsequence 
        cout<<output<<endl;
        return;
    }


    // apna one case concept ab - inclusion and exclusion waala 
    // exclude 
    print_sub_sequence(input, output, iterator + 1);

    // include : idhar merko ek character add on krna kyuki mereko us particular character to add krna hai 
    output.push_back(input[iterator]);
    print_sub_sequence(input, output, iterator + 1);

    
}


int main(int argc, char const *argv[])
{
    string input = "abc";
    string output = "";

    int iterator = 0;
    print_sub_sequence(input, output,iterator);


        
    return 0;
}
