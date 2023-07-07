#include <iostream>

using namespace std;

class Queue
{
    private:
            int* arr;
            int n; // size of the queue
            int front;
            int rear;
    public:
            // initializing the queue of size 
            Queue(int size)
            {
                this->n = size;
                arr = new int[n];
                // when the queue is empty then the front and rear = 0
                front = 0;
                rear = 0;
            }
            // Push function : to enter the value in the queue
            // value is entered from the back of the queue
            void Push(int value)
            {
                // check for the overflow first if the queue is full then
                // the value can't be inserted
                if (rear == n)
                {
                    cout<<"Queue is full"<<endl;
                    return;
                }
                else
                {
                    arr[rear] = value;
                    rear++;
                }
            }
            // Pop function : to exit the value in the queue
            // the value is deleted from the front of the queue
            void Pop()
            {
                // Check for the underflow condition, if queue is empty 
                // the value can't be deleted 
                if (front == rear)
                {
                    cout<<"Queue is Empty!!"<<endl;
                    return;
                }
                else
                {
                    cout<<"Value is popped from the front of the queue"<<endl;
                    arr[front] = -1;
                    front++;
                    // if after deletion the queue is empty then set 
                    // front = rear = 0
                    if (front == rear)
                    {
                        front = 0;
                        rear  = 0;
                    }   
                }
            }
            // get the front element of the queue
            int GetFront(){
                if (front == rear)
                {
                    cout<<"Queue is Empty!!"<<endl;
                    return -1;
                }
                else
                {
                    return arr[front];
                }
            }
            // get the size of the queue
            int GetSize(){
                return abs(front - rear);
            }

};

int main()
{
    
    Queue q(10);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    q.Push(6);

    cout<<"size of the queue is "<<q.GetSize()<<endl;

    cout<<"front element is "<<q.GetFront()<<endl;    
    q.Pop();
    cout<<"front element is "<<q.GetFront()<<endl;
    cout<<"size of the queue is "<<q.GetSize()<<endl;
    return 0;
}
