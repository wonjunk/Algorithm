#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

int Map[52][52] = { 0 };
int visitied[52][52] = { 0 };
int Altitude[52][52] = { 0 };
int Fatigue[52][52] = { 0 };

struct location {
	int x, y;
};

struct PostTo {
	int x, y, Fatigue;
};

struct Post {
	int x, y, altitude;
};

struct compPost {
	bool operator()(const Post& i, const Post& j) const {
		return i.altitude < j.altitude;
	}
} CompPost;

struct comp {
	bool operator()(const PostTo& i, const PostTo& j) const {
		return i.Fatigue < j.Fatigue;
	}
} Comp;

class mailman {
private:
	location loc;
	int max_altitude = INT_MIN;
	int min_altitude = INT_MAX;

public:
	void setloc(int x, int y);
	void setMaxaltitude(int x);
	void setMinaltitude(int x);
	void setFatigue(int x);
	location getloc();
	int getFatigue();
	int getMaxal();
	int getMinal();

};

void input();
void solve();

mailman hsd;
queue<PostTo> qq;
vector<PostTo> vec;
int min_Fatigue;

int main(void) {
	input();
	solve();

	return 0;
}

void input() {
	PostTo p;
	Post alti;
	vector<Post> v;
	char data;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> data;
			if (data == 'P') {
				hsd.setloc(i, j);
			}
			else if (data == 'K') {
				p.x = i;
				p.y = j;
				alti.x = i;
				alti.y = j;
				alti.altitude = 0;
				qq.push(p);
				v.push_back(alti);

				Map[i][j] = 1;
			}
			else {
				Map[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
				cin >> Altitude[i][j];
				Fatigue[i][j] = INT_MAX;
		}
	}

	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		iter->altitude = Altitude[iter->x][iter->y];
	}
	sort(v.begin(), v.end(), CompPost);
	min_Fatigue = abs(v.front().altitude - v.back().altitude);

	int altitude = Altitude[hsd.getloc().x][hsd.getloc().y];
	hsd.setMaxaltitude(altitude);
	hsd.setMinaltitude(altitude);
}

void solve() {
	queue<mailman> q;
	q.push(hsd);
	if (Fatigue[hsd.getloc().x][hsd.getloc().y] > hsd.getFatigue()) {
		Fatigue[hsd.getloc().x][hsd.getloc().y] = hsd.getFatigue();
	}

	mailman man;
	mailman push_man;
	int al;
	while (!q.empty()) {
		man = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			push_man.setloc(man.getloc().x + dx[i], man.getloc().y + dy[i]);
			push_man.setMaxaltitude(man.getMaxal());
			push_man.setMinaltitude(man.getMinal());
			al = Altitude[push_man.getloc().x][push_man.getloc().y];
			if (push_man.getloc().x < 1 || push_man.getloc().x > n || push_man.getloc().y < 1 || push_man.getloc().y > n) {
				continue;
			}
			if (Fatigue[push_man.getloc().x][push_man.getloc().y] <= push_man.getFatigue()) {
				continue;
			}
			if (al > man.getMaxal()) {
				push_man.setMaxaltitude(al);
			}
			else if (al < man.getMinal()) {
				push_man.setMinaltitude(al);
			}
			q.push(push_man);
			if (Fatigue[push_man.getloc().x][push_man.getloc().y] > push_man.getFatigue()) {
				Fatigue[push_man.getloc().x][push_man.getloc().y] = push_man.getFatigue();
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Fatigue[i][j] << " ";
		}
		cout << "\n";
	}

	PostTo temp;
	while (!qq.empty()) {
		temp = qq.front();
		qq.pop();

		temp.Fatigue = Fatigue[temp.x][temp.y];
		vec.push_back(temp);
	}
	
	sort(vec.begin(), vec.end(), Comp);

	if (vec.back().Fatigue > min_Fatigue) {
		cout << vec.back().Fatigue << "\n";
	}
	else {
		cout << min_Fatigue << "\n";
	}

}

void mailman::setloc(int x, int y) {
	this->loc.x = x;
	this->loc.y = y;
}

void mailman::setMaxaltitude(int x) {
	this->max_altitude = x;
}

void mailman::setMinaltitude(int x) {
	this->min_altitude = x;
}


location mailman::getloc() {
	return this->loc;
}

int mailman::getFatigue() {
	return this->max_altitude - this->min_altitude;
}

int mailman::getMaxal() {
	return this->max_altitude;
}
int mailman::getMinal() {
	return this->min_altitude;
}