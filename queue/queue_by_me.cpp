#include <iostream>

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

            }
            void pop()
            {
                
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