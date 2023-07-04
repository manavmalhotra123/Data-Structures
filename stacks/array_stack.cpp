#include <iostream>

using namespace std;

class Stack
{
    public:
            int* arr;
            int top;
            int size;

            Stack(int size){
                arr = new int[size];
                this->size = size;
                top = -1;
            }

            // function 
            void push(int data){
                if (top == size - 1)
                {
                    cout<<"STACK OVERFLOW!!"<<endl;
                    return;
                }
                
                top++;
                arr[top] = data;
            }

            void pop(){
                if (top == -1)
                {
                    cout<<"STACK UNDERFLOW!!, Nothing can be pop out..."<<endl;
                    return;
                }
                
                top --;
                
            }

            int Top(){
                if (top == -1)
                {
                    cout<<"STACK IS EMPTY!!, Nothing is here.."<<endl;
                    return -1;
                }
                
                return arr[top];
            }

            int Size(){
                return (top+1);
            }

            bool IsEmpty(){
                if (top == -1)
                {
                    return true;
                }
                return false;
                
            }

            void print(){
                if (top == -1)
                {
                    cout<<"STACK IS EMPTY!!, Nothing is here.."<<endl;
                    return;
                }
                else{
                    cout<<"STACK"<<endl;
                    while (top != -1)
                    {
                        cout<<arr[top]<<endl;
                        top --;
                    }
                    cout<<endl;
                }                
            }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
