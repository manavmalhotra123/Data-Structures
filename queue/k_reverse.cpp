#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void Show(queue<int> input) {
    cout << "Queue: ";
    while (!input.empty()) {
        cout << input.front() << " ";
        input.pop();
    }
    cout << endl;
}

void Reverse(queue<int> &input, int k) {
    stack<int> reverse;
    queue<int> support;
    int count = 0;

    // Reverse the first k elements and store them in a stack
    while (count < k) {
        reverse.push(input.front());
        input.pop();
        count++;
    }
    
    // Transfer remaining elements to a support queue
    while (!input.empty()) {
        support.push(input.front());
        input.pop();
    }
    
    // Transfer elements from the stack back to the input queue
    while (!reverse.empty()) {
        input.push(reverse.top());
        reverse.pop();
    }
    
    // Transfer remaining elements from the support queue back to the input queue
    while (!support.empty()) {
        input.push(support.front());
        support.pop();
    }
}

int main() {
    queue<int> Q;
    Q.push(1);    
    Q.push(2);    
    Q.push(3);    
    Q.push(4);    
    Q.push(5);   
    Show(Q); 
    
    Reverse(Q, 3);
    Show(Q);
    
    return 0;
}
