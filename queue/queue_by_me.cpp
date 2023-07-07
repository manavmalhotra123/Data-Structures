#include <iostream>
#include <vector>

using namespace std;

class Queue
{
    private:
            int front;
            int rear;
            int size;
            int* arr;
    public:
            Queue(int size)
            {
                arr = new int[size]; // queue of size is created 
                // front and rear is equal to zero when the queue is empty 
                front = 0;
                rear = 0;
            }
            void push(int value)
            {
                if (rear == size)
                {
                    return; // if full hai toh kya hi insert kroge ab yaar tum 
                }
                
            }
            void pop()
            {
                // check first whether the queue is empty or not 
                if (front == rear)
                {
                    return;
                }
                
            }
            void GetFront()
            {

            }
            void GetRear()
            {

            }
            void GetSize()
            {

            }
};

void SHow(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}


void shift(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        int temp = v[i+1];
        v[i+1] = v[i];
        v[i] = temp;
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    SHow(v);
    shift(v);
    SHow(v);
    return 0;
}
