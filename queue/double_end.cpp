#include <iostream>

using namespace std;

class Deque
{
    private:
        int* arr;
        int n; // size of the deque
        int front;
        int rear;

    public:
        // initializing the deque of size 
        Deque(int size)
        {
            this->n = size;
            arr = new int[n];
            // when the deque is empty then the front and rear = -1
            front = -1;
            rear = -1;
        }

        // Push function : to enter the value at the front of the deque
        void PushFront(int value)
        {
            // check for the overflow first if the deque is full then
            // the value can't be inserted
            if (IsFull())
            {
                cout << "Deque is full" << endl;
                return;
            }
            else if (IsEmpty())
            {
                front = 0;
                rear = 0;
            }
            else if (front == 0)
            {
                front = n - 1;
            }
            else
            {
                front--;
            }

            arr[front] = value;
        }

        // Push function : to enter the value at the rear of the deque
        void PushRear(int value)
        {
            // check for the overflow first if the deque is full then
            // the value can't be inserted
            if (IsFull())
            {
                cout << "Deque is full" << endl;
                return;
            }
            else if (IsEmpty())
            {
                front = 0;
                rear = 0;
            }
            else if (rear == n - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }

            arr[rear] = value;
        }

        // Pop function : to remove the value from the front of the deque
        void PopFront()
        {
            // Check for the underflow condition, if deque is empty 
            // the value can't be deleted 
            if (IsEmpty())
            {
                cout << "Deque is Empty!!" << endl;
                return;
            }
            else if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }

            cout << "Value is popped from the front of the deque" << endl;
            arr[front] = -1;
        }

        // Pop function : to remove the value from the rear of the deque
        void PopRear()
        {
            // Check for the underflow condition, if deque is empty 
            // the value can't be deleted 
            if (IsEmpty())
            {
                cout << "Deque is Empty!!" << endl;
                return;
            }
            else if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (rear == 0)
            {
                rear = n - 1;
            }
            else
            {
                rear--;
            }

            cout << "Value is popped from the rear of the deque" << endl;
            arr[rear] = -1;
        }

        // Get the front element of the deque
        int GetFront()
        {
            if (IsEmpty())
            {
                cout << "Deque is Empty!!" << endl;
                return -1;
            }
            else
            {
                return arr[front];
            }
        }

        // Get the rear element of the deque
        int GetRear()
        {
            if (IsEmpty())
            {
                cout << "Deque is Empty!!" << endl;
                return -1;
            }
            else
            {
                return arr[rear];
            }
        }

        // Get the size of the deque
        int GetSize()
        {
            if (IsEmpty())
            {
                return 0;
            }
            else if (front <= rear)
            {
                return rear - front + 1;
            }
            else
            {
                return n - front + rear + 1;
            }
        }

        // Check if the deque is empty
        bool IsEmpty()
        {
            return (front == -1 && rear == -1);
        }

        // Check if the deque is full
        bool IsFull()
        {
            return ((front == 0 && rear == n - 1) || (front == rear + 1));
        }
};

int main()
{
    Deque dq(10);
    dq.PushFront(1);
    dq.PushRear(2);
    dq.PushFront(3);
    dq.PushRear(4);
    dq.PushFront(5);
    dq.PushRear(6);

    cout << "Size of the deque is " << dq.GetSize() << endl;

    cout << "Front element is " << dq.GetFront() << endl;
    cout << "Rear element is " << dq.GetRear() << endl;

    dq.PopFront();
    dq.PopRear();

    cout << "Front element is " << dq.GetFront() << endl;
    cout << "Rear element is " << dq.GetRear() << endl;
    cout << "Size of the deque is " << dq.GetSize() << endl;

    return 0;
}
