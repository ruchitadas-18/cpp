#include <iostream>
#include <vector>

using namespace std;

class IStack {
public:
    int array[6];
    int top = 0;
    virtual void push(int element) = 0;
    virtual int pop() = 0;
    virtual int onTop() = 0;
    virtual int onBottom() = 0;
};

class UserDefinedQueue : public IStack {
public:

    void push(int element) override {
        array[top++] = element;
    }

    int pop() override {
        return array[top];
        top--;
    }

    int onTop() override {
        return array[0];
    }

    int onBottom() override {
        return array[4];
    }
};

class IReversedStack {
public:
    virtual void push() = 0;
    virtual int pop() = 0;
    virtual int onTop() = 0;
    virtual int onBottom() = 0;
};

class UserDefinedReversedQueue : public IReversedStack {
public:
    IStack* originalQueue;

    UserDefinedReversedQueue(IStack* original) : originalQueue(original) {}

    void push() override {
        originalQueue->push(originalQueue->pop());
    }

    int pop() override {
        return 0;
    }

    int onTop() override {
        return originalQueue->array[0];
    }

    int onBottom() override {
        return originalQueue->array[4];
    }
};

int main() {

    UserDefinedQueue originalQueue;
    originalQueue.push(10);
    originalQueue.push(20);
    originalQueue.push(30);
    originalQueue.push(40);
    originalQueue.push(50);

    UserDefinedReversedQueue reversedQueue(&originalQueue);

    cout << "Original Queue:" << endl;
    cout << "Top: " << originalQueue.onTop() << endl;
    cout << "Bottom: " << originalQueue.onBottom() << endl;

    cout << "Reversed Queue:" << endl;
    cout << "Top: " << reversedQueue.onTop() << endl;
    cout << "Bottom: " << reversedQueue.onBottom() << endl;

    return 0;
}
