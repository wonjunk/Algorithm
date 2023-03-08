#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

#define ADD 1
#define SORT 2
#define APPEND 3

#define LESS 0
#define GREATER 1
#define SHORTER 2

using namespace std;

class dict {
private:
	vector<string> str_list;
	string str;

	void lower();

public:
	void _init();
	void _add();
	void _sort();
	void _append();
};

struct comp {
	bool operator()(const string& i, const string& j) const {
		if (i.size() == j.size()) {
			return i < j;
		}
		else {
			return i.size() < j.size();
		}
	}
} shorter;

void input();
void solve();

int nQuery, query, c;
dict dictionary;


int main(void) {
	input();
	solve();	

	return 0;
}

void input() {
	cin >> nQuery;
	dictionary._init();
}

void solve() {
	while (nQuery--) {
		cin >> query;
		switch (query) {
		case ADD:
			dictionary._add();
			break;
		case SORT:
			dictionary._sort();
			break;
		case APPEND:
			dictionary._append();
			break;
		default:
			break;
		}
	}
}

void dict::lower() {
	for (auto iter = this->str.begin(); iter != this->str.end(); ++iter) {
		if (!islower(*iter)) {
			*iter = tolower(*iter);
		}
	}
}

void dict::_init() {
	this->str_list.reserve(nQuery);
}

void dict::_add() {
	cin >> this->str;
	this->lower();
	this->str_list.push_back(this->str);
}

void dict::_sort() {
	cin >> c;

	switch (c) {
	case LESS:
		partial_sort(this->str_list.begin(), this->str_list.begin() + 3, this->str_list.end(), less<string>());
		break;
	case GREATER:
		partial_sort(this->str_list.begin(), this->str_list.begin() + 3, this->str_list.end(), greater<string>());
		break;
	case SHORTER:
		partial_sort(this->str_list.begin(), this->str_list.begin() + 3, this->str_list.end(), shorter);
		break;
	default:
		break;
	}

	for (auto iter = this->str_list.begin(); iter != this->str_list.begin() + 3; ++iter) {
		cout << *iter << " ";
	}
	cout << "\n";
}

void dict::_append() {
	cin >> this->str;
	this->lower();
	this->str_list.front() = this->str_list.front() + this->str;
	if (this->str_list.front().size() > 15) {
		this->str_list.front() = this->str_list.front().erase(15);
	}
	cout << this->str_list.front() << "\n";
}