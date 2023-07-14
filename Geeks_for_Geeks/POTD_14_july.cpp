class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into stack1.
    void push1(int x) {
        if (top2 - top1 == 1) {
            return; // Stack 1 is full
        }
        else {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into stack2.
    void push2(int x) {
        if (top2 - top1 == 1) {
            return; // Stack 2 is full
        }
        else {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from the top of stack1.
    int pop1() {
        if (top1 < 0) {
            return -1; // Stack 1 is empty
        }
        else {
            int temp = arr[top1];
            top1--;
            return temp;
        }
    }

    // Function to remove an element from the top of stack2.
    int pop2() {
        if (top2 == size) {
            return -1; // Stack 2 is empty
        }
        else {
            int temp = arr[top2];
            top2++;
            return temp;
        }
    }
};
