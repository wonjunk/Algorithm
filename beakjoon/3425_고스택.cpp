#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define NUM 0
#define POP 1
#define INV 2
#define DUP 3
#define SWP 4
#define ADD 5
#define SUB 6
#define MUL 7
#define DIV 8
#define MOD 9

bool program_exit = false;

using namespace std;

class GoStack {
private:
	stack<long long int>* data;
	vector<pair<int,long long int>>* CMD;
	int current_step;
	bool isError = false;

	void gCMDINIT();
	void gDATAINIT();

public:
	GoStack() {
		data = new stack<long long int>();
		CMD = new vector<pair<int, long long int>>();
		CMD->reserve(1000000);
		current_step = 0;
	}
	void INIT();
	void RUN(long long int n);
	void gNUM(long long int value);
	void gPOP();
	void gINV();
	void gDUP();
	void gSWP();
	void gADD();
	void gSUB();
	void gMUL();
	void gDIV();
	void gMOD();
	void gCLEAR();
	void return_result();
};

int main(void) {
	int forloop;
	long long int input;
	GoStack* gostack = new GoStack();

	while (true) {
		gostack->INIT();
		if (program_exit) { break; }

		cin >> forloop;
		for (int i = 0; i < forloop; i++) {
			cin >> input;
			gostack->RUN(input);
		}
		cout << "\n";
	}

	return 0;
}

void GoStack::gCMDINIT() {
	this->CMD->clear();
	this->current_step = 0;
}
void GoStack::gDATAINIT() {
	while (!data->empty()) { data->pop(); }
	isError = false;
}

void GoStack::INIT() {
	this->gCMDINIT();
	this->gDATAINIT();
	string cmd;
	long long int data;

	while (true) {
		cin >> cmd;
		if (cmd == "NUM") { cin >> data; this->CMD->push_back({ 0, data }); }
		else if (cmd == "POP") { this->CMD->push_back({ 1, 0 }); }
		else if (cmd == "INV") { this->CMD->push_back({ 2, 0 }); }
		else if (cmd == "DUP") { this->CMD->push_back({ 3, 0 }); }
		else if (cmd == "SWP") { this->CMD->push_back({ 4, 0 }); }
		else if (cmd == "ADD") { this->CMD->push_back({ 5, 0 }); }
		else if (cmd == "SUB") { this->CMD->push_back({ 6, 0 }); }
		else if (cmd == "MUL") { this->CMD->push_back({ 7, 0 }); }
		else if (cmd == "DIV") { this->CMD->push_back({ 8, 0 }); }
		else if (cmd == "MOD") { this->CMD->push_back({ 9, 0 }); }
		else if (cmd == "END") { break; }
		else if (cmd == "QUIT") { program_exit = true; break; }
	}
}

void GoStack::RUN(long long int n) {
	this->gDATAINIT();
	data->push(n);

	for (vector<pair<int, long long int>>::iterator iter = this->CMD->begin(); iter != this->CMD->end(); ++iter) {
		if (isError) { break; }
		switch (iter->first) {
		case NUM:
			this->gNUM(iter->second);
			break;
		case POP:
			this->gPOP();
			break;
		case INV:
			this->gINV();
			break;
		case DUP:
			this->gDUP();
			break;
		case SWP:
			this->gSWP();
			break;
		case ADD:
			this->gADD();
			break;
		case SUB:
			this->gSUB();
			break;
		case MUL:
			this->gMUL();
			break;
		case DIV:
			this->gDIV();
			break;
		case MOD:
			this->gMOD();
			break;
		}

	}
	return_result();
}

void GoStack::gNUM(long long int value) {
	this->data->push(value);
}
void GoStack::gPOP(){
	if (this->data->empty()) { this->isError = true; return; }
	this->data->pop();
}
void GoStack::gINV(){
	if (this->data->empty()) { return; }
	long long int top = -1 * this->data->top(); this->data->pop();
	this->data->push(top);
}
void GoStack::gDUP(){
	if (this->data->empty()) { return; }
	this->data->push(this->data->top());
}
void GoStack::gSWP(){
	if (data->size() < 2) { this->isError = true; return; }
	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();

	this->data->push(first);
	this->data->push(second);
}
void GoStack::gADD(){
	if (data->size() < 2) { this->isError = true; return; }
	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();
	
	long long int result = second + first;
	if (result > 1000000000 || result < -1000000000) { this->isError = true; return; }

	this->data->push(result);
}
void GoStack::gSUB(){
	if (data->size() < 2) { this->isError = true; return; }
	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();

	long long int result = second - first;
	if (result > 1000000000 || result < -1000000000) { this->isError = true; return; }

	this->data->push(result);
}
void GoStack::gMUL(){
	if (data->size() < 2) { this->isError = true; return; }
	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();

	long long int result = second * first;
	if(result > 1000000000 || result < -1000000000) { this->isError = true; return; }

	this->data->push(result);
}
void GoStack::gDIV(){
	if (data->size() < 2) { this->isError = true; return; }

	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();
	if (first == 0) { this->isError = true; return; }
	
	long long int result = abs(second) / abs(first);
	if (first * second < 0) {
		result *= -1;
	}

	this->data->push(result);
}
void GoStack::gMOD(){
	if (data->size() < 2) { this->isError = true; return; }
	long long int first = this->data->top(); this->data->pop();
	long long int second = this->data->top(); this->data->pop();

	if (first == 0) { isError = true; return; }
	long long int result = (second / abs(second)) * (abs(second) % abs(first));

	this->data->push(result);
}

void GoStack::return_result() {
	if (this->isError == true) {
		cout << "ERROR" << "\n";
	}
	else {
		if (this->data->size() == 1) {
			cout << this->data->top() << "\n";
		}
		else {
			cout << "ERROR" << "\n";
		}
	}
}