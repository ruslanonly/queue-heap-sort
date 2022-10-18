#pragma once

class Queue {
private:
    int* arr;
public:
    unsigned long long int N_op;
    int front, rear, capacity;

    Queue(int cap);
    ~Queue();
    int size();
    int pop();
    void push(int new_item);
};

Queue::Queue(int cap) {
    N_op = 0;
    capacity = cap;
    front = rear = 0;
    arr = new int[capacity];
}

Queue::~Queue() {
    delete arr;
}

int Queue::size() {
    return rear;
}

int Queue::pop() {
    if (front == rear) {
        N_op++;
        return -1;
    } N_op += 1;
    int output = arr[front]; N_op += 2;

    int rearDec1 = rear - 1; N_op += 2;
    N_op += 2;
    for (int i = 0; i < rearDec1; i++) {
        N_op += 2;
        arr[i] = arr[i + 1]; N_op += 4;
    }
    rear--; N_op += 1;
    
    N_op += 1; return output;
}

void Queue::push(int new_item) {
    N_op += 1;
    if (rear == capacity) {
        //cout << "Queue is full" << endl;
        return;
    } N_op += 1;
    arr[rear] = new_item; N_op += 2;
    rear++; N_op += 2;
}