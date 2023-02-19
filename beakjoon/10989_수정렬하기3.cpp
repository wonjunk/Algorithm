#include <iostream>

using namespace std;


int main(void) {

	int n;
	cin >> n;

	int input;
	int* arr = new int[10001]{ 0 };

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[input]++;
	}


	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	delete[] arr;

	return 0;
}