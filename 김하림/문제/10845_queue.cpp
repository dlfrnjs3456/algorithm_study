#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int N;
	int x;
	string s;
	queue<int> que;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			que.push(x);
		}
		else if (s == "pop") {
			if (que.size()!=0) {
				int pop = que.front();
				cout << pop << endl;
				que.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (s == "size") {
			cout << que.size() << endl;
		}
		else if (s == "empty") {
			if (que.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (s == "front") {
			if (que.empty())
				cout << -1 << endl;
			else
				cout << que.front() << endl;
		}
		else if (s == "back") {
			if (que.empty())
				cout << -1 << endl;
			else
				cout << que.back() << endl;
		}
		else break;
	}
}