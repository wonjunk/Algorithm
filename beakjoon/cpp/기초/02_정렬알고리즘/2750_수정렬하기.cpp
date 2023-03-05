#include <iostream>

using namespace std;

void MergeSort(int* arr, int begin, int end, int* aux);

int main(void) {

	int n;
	cin >> n;

	int* arr = new int[n];
	int* aux = new int[n];

	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	MergeSort(arr, 0, n - 1, aux);

	for (int i = 0; i < n; i++) { cout << arr[i] << "\n"; }

	delete[] arr;
	delete[] aux;
	return 0;
}

void MergeSort(int* arr, int begin, int end, int* aux) {
	if (begin >= end) return;

	int mid = begin + (end - begin) / 2;
	MergeSort(arr, begin, mid, aux);
	MergeSort(arr, mid + 1, end, aux);

	int pointer = begin;
	int frontp = begin;
	int backp = mid + 1;

	while (frontp <= mid && backp <= end) {
		if (arr[frontp] < arr[backp]) { aux[pointer++] = arr[frontp++]; }
		else { aux[pointer++] = arr[backp++]; }
	}

	while (frontp <= mid) { aux[pointer++] = arr[frontp++]; }
	while (backp <= end) { aux[pointer++] = arr[backp++]; }

	for (int i = begin; i <= end; i++) {
		arr[i] = aux[i];
	}
}