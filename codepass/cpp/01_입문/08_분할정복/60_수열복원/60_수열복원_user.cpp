#include <iostream>

using namespace std;

extern int orderCheck(int left, int right);
void divide_conquer(int* arr, int begin, int end, int* temp);

void array_restore(int arrCount, int dat[]) {
    // implement here
    int* order = new int[arrCount];
    int* temp = new int[arrCount];

    for (int i = 0; i < arrCount; i++) {
        order[i] = i;
    }

    divide_conquer(order, 0, arrCount - 1, temp);

    for (int i = 0; i < arrCount; i++) {
        dat[order[i]] = i + 1;
    }
    delete[] order;
    delete[] temp;
}

void divide_conquer(int* arr, int begin, int end, int* temp) {
    if (begin >= end) { return; }
    int mid = (begin + end) / 2;

    divide_conquer(arr, begin, mid, temp);
    divide_conquer(arr, mid + 1, end, temp);

    int first = begin; int second = mid + 1; int indicator = begin;
    while (first <= mid && second <= end) {
        if (orderCheck(arr[first], arr[second])) { temp[indicator++] = arr[first++]; }
        else { temp[indicator++] = arr[second++]; }
    }

    while (first <= mid) { temp[indicator++] = arr[first++]; }
    while (second <= end) { temp[indicator++] = arr[second++]; }

    for (int i = begin; i <= end; i++) {
        arr[i] = temp[i];
    }
}