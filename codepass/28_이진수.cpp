#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int pow_num = 1;
    int result = 0;
    for (int i = str.length() - 1; i >= 0; i—) {
        result += ((int)str[i] - 48) * pow_num;
        pow_num *= 2;
    }

    cout << result << "\n";

    return 0;
}