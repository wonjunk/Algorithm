#include <iostream>
#include <list>

#define CMD_INSERT 1
#define CMD_ERASE 2
#define CMD_SORT 3
#define CMD_PRINT 4

#define FRONT 0
#define BACK 1

using namespace std;

class Data_List {
private:
	/// Variable
	list<int> data;

	struct Compare {
		int value = 0;
		bool operator()(const int a, const int b) const {
			if (abs(this->value - a) != abs(this->value - b)) {
				return abs(this->value - a) < abs(this->value - b);
			}
			else{
				return a < b;
			}
		}
	} comp;

public:
	void cmd_insert(int pos, int value);
	void cmd_erase(int pos, int value);
	void cmd_sort(int value);
	void cmd_print(int pos);
};

int main(void) {
	int q; // Number of Command
	int cmd; // command;
	int pos, value; //input value

	Data_List* list = new Data_List();

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> cmd;
		switch (cmd) {
		case CMD_INSERT:
			cin >> pos >> value;
			list->cmd_insert(pos, value);
			break;

		case CMD_ERASE:
			cin >> pos >> value;
			list->cmd_erase(pos, value);
			break;

		case CMD_SORT:
			cin >> value;
			list->cmd_sort(value);
			break;

		case CMD_PRINT:
			cin >> pos;
			list->cmd_print(pos);
			break;
		}
	}

	return 0;
}

void Data_List::cmd_insert(int pos, int value) {
	switch (pos){
	case FRONT:
		this->data.push_front(value);
		break;
	case BACK:
		this->data.push_back(value);
		break;
	default:
		break;
	}
}
void Data_List::cmd_erase(int pos, int value) {
	int count = 0;
	switch (pos) {
	case FRONT:
		for (auto iter = this->data.begin(); iter != this->data.end();) {
			if (*iter >= value) {
				iter = this->data.erase(iter);
				count++;
			}
			else { ++iter; }

			if (count == 3) { break; }
		}
		break;
	case BACK:
		for (auto iter = this->data.end(); iter != this->data.begin();) {
			--iter;
			if (*iter >= value) {
				iter = this->data.erase(iter);
				count++;
			}
			if (count == 3) { break; }
		}
		break;
	default:
		break;
	}
}
void Data_List::cmd_sort(int value) {
	this->comp.value = value;
	this->data.sort(comp);
}
void Data_List::cmd_print(int pos) {
	switch (pos) {
	case FRONT:
		for (auto iter = this->data.begin(); iter != this->data.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << "\n";
		break;
	case BACK:
		for (auto iter = this->data.rbegin(); iter != this->data.rend(); ++iter) {
			cout << *iter << " ";
		}
		cout << "\n";
		break;
	default:
		break;
	}
}