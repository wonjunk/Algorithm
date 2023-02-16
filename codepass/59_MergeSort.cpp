/// 입력 : 입력 숫자의 개수 n -> i번째 숫자 입력
/// 출력 : 병합 정렬을 이용하여 정렬되는 메커니즘 출력

#include <iostream>

using namespace std;

int* input(int* n);
void MergeSort(int* arr, int begin, int end, int* temp);

int n;
int main(void) {
	int* arr = input(&n);
	int* temp = new int[n];
	MergeSort(arr, 0, n-1, temp);

	return 0;
}

int* input(int* n) {
	cin >> *n;

	int* arr = new int[*n];
	for (int i = 0; i < *n; i++) {
		cin >> arr[i];
	}
	
	return arr;
}

void MergeSort(int* arr, int begin, int end, int* temp) {
	if (begin >= end) { return; }

	int mid = (begin + end) / 2;
	MergeSort(arr, begin, mid, temp);
	MergeSort(arr, mid + 1, end, temp);

	int i = begin;
	int j = mid + 1;
	int k = begin;

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) { temp[k++] = arr[i++]; }
		else { temp[k++] = arr[j++]; }
	}

	while (i <= mid) { temp[k++] = arr[i++]; }
	while (j <= end) { temp[k++] = arr[j++]; }

	for (int i = begin; i <= end; i++) {
		arr[i] = temp[i];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}