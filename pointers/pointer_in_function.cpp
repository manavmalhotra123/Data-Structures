    #include<iostream>
    #include<algorithm>

    using namespace std;

    void solve(int arr[]){
        
        cout<<"Size of array in function is "<<sizeof(arr)<<endl;
    }

    int main(int argc, char const *argv[])
    {
        int arr[4];
        cout<<"Size of array: "<<sizeof(arr)<<endl; // it will print 16 as size as the size of whole array is calculated

        solve(arr);  // it will print 8 as in function we always give array reference or pointer as a parameter and we all know that the size of pointer is always 8
        return 0;
    }
