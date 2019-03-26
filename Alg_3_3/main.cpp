/*
Реализовать очередь с помощью двух стеков.
Использовать стек, реализованный с помощью динамического буфера.
*/

#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    Stack() : top(-1) {     //констркутор
        sizeOfStack = 2;
        stack = new int[sizeOfStack];
    }

    ~ Stack() {             //деструктор
        delete [] stack;
    }

    void push(int num) {
        if(top+1 >= sizeOfStack) {
            stackIncrease();
        }
        stack[++top] = num;
    }

    int pop() {
        if(top == -1) {
            return -1;
        } else {
            return stack[top--];
        }
    }
    int getTop() {
        return top;
    }

private:
    int* stack;
    int sizeOfStack;
    int top;
    void stackIncrease() {        //увеличение развера буфера в два раза
        int newSizeOfStack = sizeOfStack*2;
        int* newStack = new int[newSizeOfStack];
        for (int i=0; i<sizeOfStack; i++) {
            newStack[i] = stack[i];
        }
        delete [] stack;
        stack = newStack;
        sizeOfStack *=2;
    }
};

class Queue {
public:
    Queue() {
    }
    ~ Queue() {
    }

    void push(int num) {
        stack1.push(num);
    }

    int pop() {
        if(stack2.getTop() == -1) {
            while(stack1.getTop() != -1) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }
private:
    Stack stack1, stack2;
};

int main() {

    int n;
    cin >> n;

    Queue queue;
    for(int i=0; i < n; i++) {
        int command, num;
        cin >> command >> num;
        switch(command) {
            case 2:
                if(queue.pop() != num) {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 3:
                queue.push(num);
                break;
        }
    }
    cout << "YES" << endl;

    return 0;
}
