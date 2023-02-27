
#include <iostream>

using namespace std;

int main(void) {
    int N, M;
    int sum = 0;
    int min = 0;
    cin >> N >> M;

    bool* arr = new bool[M + 1] {0};
    arr[1] = true;

    for (int i = 2; i <= M; i++) {
        if (arr[i] == true) continue;
        for (int j = 2 * i; j <= M; j = j + i) {
            arr[j] = true;
        }
    }

    for (int i = N; i <= M; i++) {
        if (arr[i] == false) {
            min = i;
            break;
        }
    }

    for (int i = N; i <= M; i++) {
        if (arr[i] == false) {
            sum += i;
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    }
    else {
        cout << sum << endl;
        cout << min << endl;
    }

    delete[] arr;
    return 0;
}