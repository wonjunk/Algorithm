#include <iostream>
#include <vector>
#include <algorithm>

#define lang_C 0
#define lang_Java 1
#define lang_Python 2


using namespace std;

struct developer {
	int pid;
	int C, J, P;
	int salary;

	developer() {
		this->pid = 0;
		this->C = 0;
		this->J = 0;
		this->P = 0;
		this->salary = 0;
	}

	developer(int pid, int C, int J, int P, int salary) {
		this->pid = pid;
		this->C = C;
		this->J = J;
		this->P = P;
		this->salary = salary;
	}
	
};

struct min_Comp {
	bool operator()(const developer& a, const developer& b) const {
		if (a.salary != b.salary) { return a.salary > b.salary; }
		else { return a.pid > b.pid; }
	}
} minComp;

struct max_Comp {
	bool operator()(const developer& a, const developer& b) const {
		double a_average = (a.C + a.J + a.P) / 3.0;
		double b_average = (b.C + b.J + b.P) / 3.0;
		if (a_average != b_average) { return a_average < b_average; }
		else { return a.pid < b.pid; }
	}
} maxComp;

class app {
private:
	vector<developer>* data = new vector<developer>();

public:

	void Register(developer dev);
	void Cancel(int pid);
	void Update(int pid, int flag, int value);
	void hire_min();
	void hire_max();
};

int main(void) {
	int Q;
	string CMD;
	cin >> Q;

	int pid, C, J, P, salary, flag, value;
	developer* dev;
	app* application = new app();

	while (Q--) {
		cin >> CMD;
		if (CMD == "register") {
			cin >> pid >> salary >> C >> J >> P;
			dev = new  developer(pid, C, J, P, salary);
			application->Register(*dev); }
		else if (CMD == "cancel") {
			cin >> pid;
			application->Cancel(pid); 
		}
		else if (CMD == "update") {
			cin >> pid >> flag >> value;
			application->Update(pid, flag, value);
		}
		else if (CMD == "hire_min") {
			application->hire_min();
		}
		else if (CMD == "hire_max") {
			application->hire_max();
		}
	}

	return 0;
}

void app::Register(developer dev) {
	this->data->push_back(dev);
}
void app::Cancel(int pid) {
	for (auto iter = this->data->begin(); iter != this->data->end();) {
		if (iter->pid == pid) {
			iter = this->data->erase(iter);
		}
		else ++iter;
	}
}
void app::Update(int pid, int flag, int value) {
	for (auto iter = this->data->begin(); iter != this->data->end(); ++iter) {
		if (iter->pid == pid) {
			switch (flag) {
			case lang_C:
				iter->C = value;
				break;
			case lang_Java:
				iter->J = value;
				break;
			case lang_Python:
				iter->P = value;
				break;
			default:
				break;
			}
		}
	}

}
void app::hire_min() {
	sort(this->data->begin(), this->data->end(), minComp);
	cout << this->data->back().pid << "\n";
	this->data->pop_back();
	
}
void app::hire_max() {
	sort(this->data->begin(), this->data->end(), maxComp);
	for (int i = 0; i < 3; i++) {
		cout << this->data->back().pid << " ";
		this->data->pop_back();
	}
	cout << "\n";
}