// create a tree from indorder and pre-order 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

/*
            TREE
             5
            / \
           1   2
          / \
         3  4      

         INORDER: LNR : 3 1 4 5 2
         PREORDER: NLR : 5 1 3 4 2


         Preorder ki sbse pehli value tumhaari major root hogi tree ki  
                it means that 5 is the major root.

                     5

        now considering the preorder we can say that 3 1 4 lie in left subtree
        and 2 lie in right subtree 

                     5 
                    / \
              (3 1 4)  2

        ab dekh kitne element bilkul done ho gye hai - 5,2
        ab ek cheez dekh preorder mai tere pass next element konsa hai 
        and it is 1 so it is the root of left subtree
        aur jab inorder mai dekhega toh uske right left wale subtree mai daalde

             5
            / \
           1   2
          / \
         3  4      
                    
*/


int main(int argc, char const *argv[])
{


    return 0;
}