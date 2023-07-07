#include <iostream>
#include <vector>

using namespace std;
class Queue
{
    private:
            int* arr;
            int size;
            int front;
            int rear;
    public:
            Queue(int size){
                this->size = size;
                arr = new int[size];
                front = 0;
                rear = 0;
            }

            void Push(int data){
                if (rear == size)
                {
                    cout<<"Queue is full!"<<endl;
                    return;
                }
                else
                {
                    arr[rear] = data;
                    rear++;
                }
            }
            void Pop(){
                if (front == rear)
                {
                    cout<<"Queue is empty!"<<endl;
                    return;
                }
                else
                {
                    arr[front] = -1;
                    front++;
                    // agar queue khaali hogi toh usko fir start pr le aayo nah
                    if (front == rear)
                    {
                        front = 0;
                        rear = 0;
                    }
                }
            }
            int GetFront(){
                if (front == rear)
                {
                    cout<<"Queue is empty!"<<endl;
                    return -1;
                }
                else
                {
                    return arr[front];
                }
            }
            bool IsEmpty(){
                if (front == rear)
                {
                    return true;
                }
                else
                {
                    false;
                }
            }
            int GetSize(){
                return abs(front - rear );
            }
            friend void show(Queue Q);
};

void show(Queue Q){
  
}

int main(int argc, char const *argv[])
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
}
