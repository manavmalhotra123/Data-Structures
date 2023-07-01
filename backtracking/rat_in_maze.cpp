#include <iostream>
#include<vector>
using namespace std;


// to be visit position ko check krna aur if move kra toh usko visted mark kr dena 
bool isSafe(int i, int j, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  // validating the array
  if( ((i>=0 && i < row) && (j >= 0 && j< col)) && // validating the size of the maze
      (arr[i][j] == 1 ) && // checking the availability in the maze
      (visited[i][j]==false)) { // checking that it is not visited before
    return true; // if all satisfies then go to that position
  }
  else { // if something went wrong stay same position
    return false;
  }
}

void solveMaze(int arr[][4], int row,int col, int i, int j,
vector<vector<bool> > &visited, vector<string>& path, string output  ) {

  //base case : can check till we are in array that is till the limit of the maze
  if(i == row-1 && j == col-1) {
    //answer found
    path.push_back(output); // jaise hi BT huyi size waali agr koi path aaya toh use save krke rkh lo 
    return;
  } 

  //Down -> i+1, j
  if(isSafe(i+1, j, row, col, arr, visited)) // will return true or false 
   {
    visited[i+1][j] = true; // visit kr aur true mark krde
    solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtrack 
    visited[i+1][j] = false; // reserving to it's original position 
  }

  //Left -> i, j-1
  if(isSafe(i, j-1, row, col, arr, visited)) {
    visited[i][j-1] = true;
    solveMaze(arr, row, col, i, j-1, visited, path, output + 'L');
    //backtrack 
    visited[i][j-1] = false;
  }

  //Right -> i, j+1
  if(isSafe(i, j+1, row, col, arr, visited)) {
    visited[i][j+1] = true;
    solveMaze(arr, row, col, i, j+1, visited, path, output + 'R');
    //backtrack 
    visited[i][j+1] = false;
  }

  //Up-> i-1, j
if(isSafe(i-1, j, row, col, arr, visited)) {
    visited[i-1][j] = true;
    solveMaze(arr, row, col, i-1, j, visited, path, output + 'U');
    //backtrack 
    visited[i-1][j] = false;
  }


}

int main() {

  // maze array
  int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

  // if koi start hi nahi hai toh path kha se nikalenge
  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  // size of the maze 
  int row = 4;
  int col = 4;

  // copy of maze to keep the track of the visited positions
  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;

  // results store krne ke liye ek string vector aur ek string jisko push krenge vecgor mai 
  vector<string> path;
  string output = "";


  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  // if path mai kuch hoga toh results print krde 
  for(auto i: path) {
    cout << i << " ";
  }
  // else koi path mila hi nahi rat ko 
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }
  
  return 0;
}