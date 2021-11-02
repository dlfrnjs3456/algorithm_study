#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sol(int n) {
	queue <int> q;
	for (int i = 1; i < n + 1; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return q.front();
}

int main() {
	int n;
	cin >> n;
	cout << sol(n);
}
