#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Comp {
    bool operator()(const int& i, const int& j) const {
        if (abs(i) == abs(j)) {
            return i > j;
        }
        else {
            return abs(i) > abs(j);
        }
    }
};

int main(void) {
    int nQuery;
    int query;

    priority_queue<int, vector<int>, less<int> > maxpq;
    priority_queue<int, vector<int>, greater<int> > minpq;
    priority_queue<int, vector<int>, Comp> abspq;
    cin >> nQuery;

    while (nQuery--) {
        cin >> query;
        if (query == 0) {
            if (maxpq.empty() || minpq.empty() || abspq.empty()) {
                cout << -1 << " ";
            }
            else {
                cout << maxpq.top() << " " << minpq.top() << " " << abspq.top();
                maxpq.pop();
                minpq.pop();
                abspq.pop();
            }
            cout << "\n";
        }
        else {
            maxpq.push(query);
            minpq.push(query);
            abspq.push(query);
        }
    }
}