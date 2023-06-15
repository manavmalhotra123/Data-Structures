#include<vector>
#include<iostream>
using namespace std;

int main(){
    // creating a dynamic array
    int n;
    vector<int> arr(n);
    
    // entering the values in an array
    arr.push_back(1);
    arr.push_back(3);

    // printing the values of an array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    // removing the value from the vector
    arr.pop_back();
    cout<<endl;
    cout<<"after deletion"<<endl;
        // printing the values of an array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    

    // arr.empty() check that the array is empty or not
    bool check = arr.empty();

    if (check == 0)
    {
        cout<<"array is not empty"<<endl;
    }
    else {
        cout<<"array is empty"<<endl;
    }
    
    
    return 0;
}

