#include <iostream>
#include <string>
#include "Stack.cpp"

using namespace std;

class StackWithMax {
public:
    StackWithMax (int a) {
        JustStack = new Stack(a);
        MaxStack = new Stack(a);
    }

    ~StackWithMax() {
        delete JustStack;
        delete MaxStack;
    }

    void push(int a) {
        JustStack->push(a);
        if (a > MaxStack->top()) {
            MaxStack->push(a);
        }
        else {
            MaxStack->push(MaxStack->top());
        }

    }

    int pop() {
        MaxStack->pop();
        return JustStack->pop();
    }

    int getMaxElement() {
        return MaxStack->top();

    }
private:
    Stack* MaxStack;
    Stack* JustStack;
};
