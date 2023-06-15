#include<iostream>

using namespace std;


// taking array as an argument in function 
void input(int arr[], int n){
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// function taking array as an argument
void print(int arr[], int n){
    cout<<"Arrays: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<endl;
    }
    
}



int main(int argc, char const *argv[])
{
    int arr[5];
    // calling the function
    input(arr,5);
    print(arr,5);
    return 0;
}
