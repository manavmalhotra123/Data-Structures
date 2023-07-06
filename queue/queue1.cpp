// Starting the Queue -- Queue means line 
// LIFO order - Last in First Out 

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q;
    // inserting the values in the queue - from rear
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // front means the latest person to be served
    cout<<q.front()<<endl;
    // removal of the person served and moving the other people forward
    q.pop();
    // the last person in the queue who wants to get served
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    return 0;
}
