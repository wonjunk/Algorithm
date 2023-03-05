#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    int input;
    int std;
    int divisor(0), multiple(0);
    cin >> n;

    vector<int> v;
    v.reserve(n);

    while (n--) {
        cin >> input;
        v.push_back(input);
    }

    cin >> std;

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        if (std == *iter) {
            divisor += *iter;
            multiple += *iter;
        }
        else if (std % *iter == 0) {
            divisor += *iter;
        }
        else if (*iter % std == 0) {
            multiple += *iter;
        }
    }

    cout << divisor << "\n";
    cout << multiple << "\n";

    return 0;
}