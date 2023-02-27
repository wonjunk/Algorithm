#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int koi = 0;
    int ioi = 0;

    string comp;
    for (int i = 0; i < str.length() - 2; i++) {
        comp = str.substr(i, 3);
        if (comp == "KOI") {
            koi++;
            continue;
        }
        if (comp == "IOI") {
            ioi++;
            continue;
        }
    }

    cout << koi << "\n";
    cout << ioi << "\n";

    return 0;
}