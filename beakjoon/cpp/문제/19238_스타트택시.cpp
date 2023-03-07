#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct location {
	int x, y;
};

struct guest {
	location loc;
	location goal;
	int distance;

	bool operator>(const guest& j) const {
		if (this->distance == j.distance) {
			if (this->loc.y == j.loc.y) {
				return this->loc.x > j.loc.x;
			}
			else {
				return this->loc.y > j.loc.y;
			}
		}
		return this->distance > j.distance;
	}
};

class car {
private:
	location loc;
	int visited[21][21] = { 0 };
	int Distance[21][21] = { 0 };
	guest g;
	int fuel;

	void Init();
	void GetAllDistance();
	int GetDistanceToGoal();
	void FindNearest();

public:
	void Input();
	void MoveTo();
	void MoveForPay();
	int GetFuel() { return this->fuel; }
};

bool breakdown = false;
int MapSize, nGuest, Fuel;
int Map[21][21] = { 0 };
car taxi;
vector<guest> guests;
queue<pair<pair<location, int>, int>> q;

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0 , 1, 0 , -1 };

void input();
void solve();

int main(void) {
	input();
	solve();

	return 0;
}

void input() {
	cin >> MapSize >> nGuest >> Fuel;

	for (int j = 1; j <= MapSize; j++) {
		for (int i = 1; i <= MapSize; i++) {
			cin >> Map[i][j];
		}
	}
	
	taxi.Input();

	guest gst;
	while (nGuest--) {
		cin >> gst.loc.y >> gst.loc.x >> gst.goal.y >> gst.goal.x;
		guests.push_back(gst);
	}
}

void solve() {
	while (!guests.empty()) {
		taxi.MoveTo();
		if (breakdown) {
			break;
		}
		taxi.MoveForPay();
		if (breakdown) {
			break;
		}
	}
	if (breakdown) {
		cout << -1 << "\n";
	}
	else {
		cout << taxi.GetFuel() << "\n";
	}
}

void car::Input() {
	this->fuel = Fuel;
	cin >> this->loc.y >> this->loc.x;
}

void car::Init() {
	for (int j = 1; j <= MapSize; j++) {
		for (int i = 1; i <= MapSize; i++) {
			this->visited[i][j] = -1;
			this->Distance[i][j] = -1;
		}
	}

	while (!q.empty()) {
		q.pop();
	}
}

void car::GetAllDistance(){
	this->Init();
	q.push({ {this->loc, this->fuel}, 0 });
	visited[this->loc.x][this->loc.y] = 1;
	location loc, new_loc;
	int f; // fuel
	int d; // distance
	while (!q.empty()) {
		loc = q.front().first.first;
		f = q.front().first.second;
		d = q.front().second;
		q.pop();

		Distance[loc.x][loc.y] = d;

		//cout << "------------" << endl;
		//
		//for (int j = 0; j < MapSize; j++) {
		//	for (int i = 0; i < MapSize; i++) {
		//		cout << visited[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		//cout << "------------" << endl;

		for (int i = 0; i < 4; i++) {
			new_loc.x = loc.x + dx[i];
			new_loc.y = loc.y + dy[i];
			if (new_loc.x > MapSize || new_loc.x < 1 || new_loc.y > MapSize || new_loc.y < 1) continue;
			if (visited[new_loc.x][new_loc.y] == 1) continue;
			if (Map[new_loc.x][new_loc.y] == 1) continue;

			q.push({ {new_loc, f - 1}, d + 1 });
			visited[new_loc.x][new_loc.y] = 1;
		}
	}
}

int car::GetDistanceToGoal() {
	this->Init();
	q.push({ {this->loc, this->fuel}, 0 });
	visited[this->loc.x][this->loc.y] = 1;

	location loc, new_loc;
	int f = 0; // fuel
	int d = 0; // distance
	while (!q.empty()) {
		loc = q.front().first.first;
		f = q.front().first.second;
		d = q.front().second;
		q.pop();

		Distance[loc.x][loc.y] = d;
		if (loc.x == this->g.goal.x && loc.y == this->g.goal.y) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			new_loc.x = loc.x + dx[i];
			new_loc.y = loc.y + dy[i];
			if (new_loc.x > MapSize || new_loc.x < 1 || new_loc.y > MapSize || new_loc.y < 1) continue;
			if (visited[new_loc.x][new_loc.y] == 1) continue;
			if (Map[new_loc.x][new_loc.y] == 1) continue;

			q.push({ {new_loc, f - 1}, d + 1 });
			visited[new_loc.x][new_loc.y] = 1;
		}
	}
	if (d == -1) {
		breakdown = true;
	}
	return d;
}

void car::FindNearest() {
	for (auto iter = guests.begin(); iter != guests.end(); ++iter) {
		iter->distance = this->Distance[iter->loc.x][iter->loc.y];
	}
	
	sort(guests.begin(), guests.end(), greater<guest>());
	if (guests.back().distance == -1) {
		breakdown = true;
	}
}

void car::MoveTo() {
	this->GetAllDistance();
	this->FindNearest();
	this->g = guests.back();
	guests.pop_back();

	this->fuel -= this->g.distance;
	this->loc.x = this->g.loc.x;
	this->loc.y = this->g.loc.y;
	if (this->fuel < 0) {
		breakdown = true;
	}
}

void car::MoveForPay() {
	int distance = this->GetDistanceToGoal();

	this->fuel -= distance;
	this->loc.x = this->g.goal.x;
	this->loc.y = this->g.goal.y;
	if (this->fuel < 0) {
		breakdown = true;
		return;
	}
	else {
		this->fuel = this->fuel + 2 * distance;
		return;
	}
}