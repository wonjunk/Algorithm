#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MAX = (int)sqrt(2100000000);

int main(void) {
	int sq;
	int input;
	vector<int> divisors;
	cin >> input;

	sq = (int)sqrt(input);
	divisors.reserve(MAX);

	for (int i = 1; i <= sq; i++) {
		if (input % i == 0) {
			divisors.push_back(i);
			if (i != input / i) {
				divisors.push_back(input / i);
			}
		}
	}

	sort(divisors.begin(), divisors.end());

	for (auto iter = divisors.begin(); iter != divisors.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << "\n";

	return 0;
}