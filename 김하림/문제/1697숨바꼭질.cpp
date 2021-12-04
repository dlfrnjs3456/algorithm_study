#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
int n, k;
bool visited[MAX] = { 0 };

struct node {
	int loc;
	int time;
};

void bfs() {
	queue<node> q;
	q.push({n, 0});
	visited[n] = true;
	int ans = MAX;

	while (!q.empty()) {
		int curLoc = q.front().loc;
		int curTime = q.front().time;
		q.pop();
		if (curLoc == k) {
			cout << curTime << endl;
			break;
		}
		if (!visited[curLoc - 1] && 0 <= curLoc - 1 && curLoc - 1 < MAX) {
			q.push({ curLoc - 1, curTime + 1 });
			visited[curLoc - 1] = true;
		}
		if (!visited[curLoc + 1] && 0 <= curLoc + 1 && curLoc + 1 < MAX) {
			q.push({ curLoc + 1, curTime + 1 });
			visited[curLoc + 1] = true;
		}
		if (!visited[curLoc * 2] && 0 <= curLoc * 2 && curLoc * 2 < MAX) {
			q.push({ curLoc * 2, curTime + 1 });
			visited[curLoc * 2] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	bfs();

	return 0;
}