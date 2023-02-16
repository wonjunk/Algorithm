///시작 시간과 종료 시간이 예약된 회의실이 있음 -> 시간대 겹치는 회의는 동시에 개최 불가(종료시간과 시작시간이 겹치는건 괜찮)
///-> 최대한 많이 회의를 배정할 수 있는 프로그램을 짜라.
/// 
/// input : 회의의 수 n -> 회의 번호와 시작/종료 시간 N개
/// output : 개최가능한 회의 수 -> 회의의 번호를 시간대 별로 나열.(여러개라면 아무거나)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
	int number;
	int start;
	int end;
};

void input(vector<meeting>& imeet);
void solve(vector<meeting>& imeet);
bool compare(meeting i, meeting j);

int main(void) {
	vector<meeting> imeet;
	input(imeet);
	solve(imeet);

	return 0;
}

void input(vector<meeting>& imeet) {
	int n;
	meeting mInform;

	cin >> n;
	imeet.reserve(n);

	for (int i = 0; i < n; i++) {
		cin >> mInform.number >> mInform.start >> mInform.end;
		imeet.push_back(mInform);
	}
}


void solve(vector<meeting>& imeet) {
	sort(imeet.begin(), imeet.end(), compare);

	meeting now = *imeet.begin();
	vector<int> MeetingSeries;
	MeetingSeries.reserve(imeet.capacity());
	int nMeeting = 0;


	for (auto iter = imeet.begin(); iter != imeet.end(); ++iter) {
		if (now.end <= iter->start || iter == imeet.begin()) {
			nMeeting++;
			MeetingSeries.push_back(iter->number);
			now = *iter;
		}
	}

	cout << nMeeting << "\n";
	for (auto iter = MeetingSeries.begin(); iter != MeetingSeries.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << "\n";
}

bool compare(meeting i, meeting j) { return i.end < j.end; }