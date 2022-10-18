#include <iostream>
#include <ctime>
#include "Queue.h"

using namespace std;


void display(Queue* queue) {
    int n = queue -> size();
    for (int i = 0; i < n; i++) {
        cout << queue -> get(i) << " ";
    }
    cout << endl;
}

void swap(Queue* queue, int i, int j) {
    int a = queue -> get(i);
    queue -> insert(queue -> get(j), i);
    queue -> insert(a, j);
}

void heapify(Queue* queue, int n, int i)
{
    int largest = i;

    int l = 2 * i + 1; // левый 
    int r = 2 * i + 2; // правый

    if (l < n && queue -> get(l) > queue -> get(largest))
        largest = l;

    if (r < n && queue -> get(r) > queue -> get(largest))
        largest = r;
    if (largest != i)
    {
        swap(queue, i, largest);

        heapify(queue, n, largest);
    }
}

void heapSort(Queue* queue) {
    int n = queue -> size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(queue, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(queue, 0, i);
        heapify(queue, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int amounts[10] = { 300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000 };

    for (int i = 0; i < 10; i++) {
        int n = amounts[i];
        Queue* queue = new Queue(n);
        for (int i = 0; i < n; i++) {
            int a = rand() % 1000;
            queue -> push(a);
        }
        unsigned int start_time = clock();
        heapSort(queue);
        unsigned int end_time = clock();
        int process_time = end_time - start_time;
        cout << "Номер сортировки: " << i + 1 << "   ";
        cout << "Количество отсортированных элементов: " << n << "   ";
        cout << "Время сортировки (ms): " << process_time << "   ";
        cout << "Количество операций (N_op): " << queue -> N_op << "   ";
        display(queue);
        delete queue;
    }
}