// Selection Sort - minimum dhundo and usko utha ke aage aage rkhdo arram se 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int>& v){
    cout<<"vector"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


void selection_sort(vector<int>& v){

    int mini = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mini = i;
        for (int j = i+1; j < v.size(); j++)
        {
            if (int(v[j]) < v[mini])
            {
                mini = j;
            }
        }
        swap(v[i], v[mini]);
    }
    
    print_vector(v);
    
}

int main(){
    vector<int> v = { 1,2,3,5,9,10,13,14,11};
    print_vector(v);
    selection_sort(v);
    return 0;
}