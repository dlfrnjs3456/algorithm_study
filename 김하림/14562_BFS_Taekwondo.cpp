#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int s, t;
int visited[MAX];
struct node {
	int a, b;
	int level = 0;
};
void bfs() {
	queue<node> q;
	q.push({ s,t });
	//visited[s] = true;

	while (!q.empty()) {
		int curS = q.front().a;
		int curT = q.front().b;
		int lev = q.front().level;
		q.pop();
		q.push({ curS + 1, curT, lev + 1 });
		if (q.back().a == q.back().b) {
			cout << lev + 1 << endl;
			break;
		}
		//visited[curS + 1] = true;
		if (2 * curS <= curT + 3)
			q.push({ 2 * curS, curT + 3, lev + 1 });
		if (q.back().a == q.back().b) {
			cout << lev + 1 << endl;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s >> t;
		bfs();
	}
}