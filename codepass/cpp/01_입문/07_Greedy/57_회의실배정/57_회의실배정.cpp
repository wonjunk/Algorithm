///���� �ð��� ���� �ð��� ����� ȸ�ǽ��� ���� -> �ð��� ��ġ�� ȸ�Ǵ� ���ÿ� ���� �Ұ�(����ð��� ���۽ð��� ��ġ�°� ����)
///-> �ִ��� ���� ȸ�Ǹ� ������ �� �ִ� ���α׷��� ¥��.
/// 
/// input : ȸ���� �� n -> ȸ�� ��ȣ�� ����/���� �ð� N��
/// output : ���ְ����� ȸ�� �� -> ȸ���� ��ȣ�� �ð��� ���� ����.(��������� �ƹ��ų�)

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