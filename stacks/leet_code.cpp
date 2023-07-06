#include <iostream>
#include <vector>
#include <climits>

class minStack {
private:
    int* mymain;
    int* mini;
    int top;
    int size;

public:
    minStack(int size) {
        mymain = new int[size];
        mini = new int[size];
        top = -1;
        this->size = size;
    }

    void push(int value) {
        if (top == size - 1) {
            return;
        } else {
            top++;
            mymain[top] = value;
            if (top == 0 || value < mini[top - 1]) {
                mini[top] = value;
            } else {
                mini[top] = mini[top - 1];
            }
        }
    }

    void pop() {
        if (top == -1) {
            return;
        } else {
            top--;
        }
    }

    int getTop() {
        return mymain[top];
    }

    int getMinimum() {
        return mini[top];
    }
};

int main() {
    minStack s(5);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);

    std::cout << "Top element: " << s.getTop() << std::endl;
    std::cout << "Minimum element: " << s.getMinimum() << std::endl;

    return 0;
}
