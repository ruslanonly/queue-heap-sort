#include <iostream>
#include <ctime>
#include "QueueController.h"

using namespace std;

void heapify(QueueController* queue, int n, int i)
{
    int largest = i; queue->N_op++;

    int l = 2 * i + 1; queue->N_op += 3; // левый 
    int r = 2 * i + 2; queue->N_op += 3; // правый

    queue->N_op += 8;
    if (l < n && queue -> get(l) > queue -> get(largest))
        largest = l; queue->N_op += 1;

    queue->N_op += 8;
    if (r < n && queue -> get(r) > queue -> get(largest))
        largest = r; queue->N_op += 1;
    queue->N_op += 1;
    if (largest != i)
    {
        queue -> swap(i, largest); queue->N_op += 4;

        heapify(queue, n, largest); queue->N_op += 4;
    }
}

void heapSort(QueueController* queue) {
    int n = queue -> size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(queue, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        queue -> swap(0, i);
        heapify(queue, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int amounts[10] = { 300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000 };

    for (int i = 0; i < 10; i++) {
        int n = amounts[i];
        QueueController* queue = new QueueController(n);
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
        cout << endl;
        delete queue;
    }
}