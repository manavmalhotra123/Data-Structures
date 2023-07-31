#include <iostream>
#include<vector>
using namespace std;

//index = index  of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity) {
  //base case -> only 1 item
  if(index == 0 ) {
    if(weight[0] <= capacity) {
      return value[0];
    }
    else
      return 0;
  }

  //include and exclude
  int include = 0;
  if(weight[index] <= capacity)
    include = value[index] + solveUsingRecursion(weight, value, index-1, capacity - weight[index] );

  int exclude = 0 + solveUsingRecursion(weight, value, index-1, capacity);

  int ans = max(include, exclude);
  return ans;
}

  



int main() {

  int weight[] = {4,5,1};
  int value[] = {1,2,3};
  int n = 3;
  int capacity = 4;


  //int ans = solveUsingRecursion(weight, value, n-1, capacity);

  // vector<vector<int> > dp(n, vector<int>(capacity+1 , -1));
  // int ans = solveUsingMem(weight, value, n-1, capacity, dp);

    int ans = solveUsingRecursion(weight, value, n-1, capacity);
  cout << "Ans: " << ans << endl;

  return 0;
}