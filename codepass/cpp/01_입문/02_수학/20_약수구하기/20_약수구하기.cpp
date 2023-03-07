#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int number, k;
	cin >> number >> k;

	vector<int> v;
	v.reserve(number);
	
	for (int i = 1; i <= number; i++) {
		if (number % i | 0) { continue; }
		else { v.push_back(i); }
	}

	sort(v.begin(), v.end());

	if (v.size() >= k) {
		cout << v.at(k - 1) << "\n";
	}
	else {
		cout << 0 << "\n";
	}


	return 0;
}