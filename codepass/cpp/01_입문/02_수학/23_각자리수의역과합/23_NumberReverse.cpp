#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int input;
	int sum;
	int reverse;
	string str;
	string rev_str;

	while (true) {
		sum = 0;

		cin >> str;
		if (str == "0") { break; }
		rev_str = str;
		input = stoi(str);
		if (input > 2100000000 || input < 0) { continue; }

		for (int i = str.length() - 1; i >= 0; i--) {
			rev_str[str.length() - 1 - i] = str[i];
			sum = sum + (int)str[i] - 48;
		}
		reverse = stoi(rev_str);
		if (reverse > 2100000000) { continue; }

		cout << reverse << " " << sum << "\n";
	}
}