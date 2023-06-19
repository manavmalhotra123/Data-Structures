#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // nearly sorted array 
    vector<int> v = {10,3,40,20,50,80,70};

    int target = 3;

    // Approach 1 : linear search with time complexity of O(N)

    // Approach : sort and search then complexity will be O(nlog(N))

    // Approach 2 : Binary search
    // but here the array is nearly sorted 
    int start = 0;
    int end = v.size();
 
    int mid = (start + end)/2;

    int pos = -1;

    while(start <= end){
       if (v[mid] == target)
       {
        pos = mid;
        cout<<"Mil Gya!!"<<endl;
        break;
       }
       else if (v[mid+1] == target)
       {
        pos = mid + 1;
        cout<<"Mil Gya!!"<<endl;
        break;
       }
       else if (v[mid-1] == target){
        pos = mid - 1;
        cout<<"Mil Gya!!"<<endl;
        break;
       }
       else if (target > v[mid]){
        start = mid + 2;
        cout<<"Need to shift right"<<endl;
       }
       else
       {
        end = mid - 2;
        cout<<"Need to shift left"<<endl;
       }
       mid = (start + end)/2;
    }


    if (pos == -1){
       cout<<"Not found!"<<endl;
    }
    else
    {
        cout<<"Found at index "<<pos<<endl;
    }
    

    return 0;
}
