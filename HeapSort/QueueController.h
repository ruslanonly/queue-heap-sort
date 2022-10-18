#pragma once
#include "Queue.h"
class QueueController : public Queue
{
public:
    QueueController(int cap) : Queue(cap) {};
    void insert(int item, int pos);
    int get(int pos);
    void swap(int i, int j);
    void display();
};

void QueueController::swap(int i, int j) {
    int a = get(i); N_op += 3;
    insert(get(j), i); N_op += 5;
    insert(a, j); N_op += 3;
}

void QueueController::display() {
    int n = size();
    for (int i = 0; i < n; i++) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}

void QueueController::insert(int item, int pos) {
    if (pos >= rear) return; N_op += 1;
    N_op += 2;
    for (int i = 0; i < pos; i++) {
        N_op += 2;
        push(pop()); N_op += 4;
    }
    pop(); N_op += 2;
    push(item); N_op += 2;

    int rearDec1 = rear - 1; N_op += 2;
    N_op += 2;
    for (int i = pos; i < rearDec1; i++) {
        N_op += 2;
        push(pop()); N_op += 4;
    }
}

int QueueController::get(int pos) {
    N_op += 1;
    N_op += 2;
    for (int i = 0; i < pos; i++) {
        N_op += 2;
        push(pop()); N_op += 4;
    }
    int output = pop(); N_op += 3;
    push(output); N_op += 2;

    int rearDec1 = rear - 1; N_op += 2;
    N_op += 2;
    for (int i = pos; i < rearDec1; i++) { // rear - 1 to prevent deleting of last item
        N_op += 2;
        push(pop()); N_op += 4;
    }
    N_op += 1; return output;
}

