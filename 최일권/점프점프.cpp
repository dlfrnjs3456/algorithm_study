#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001] = {};
int visited[1001] = {};
int ans = -1;

struct Node {
	int cur;
	int lev;
};

int isInside(int cur) {
	if (cur <= 0 || cur > N) return 0;
	return 1;
}

void bfs() {
	queue<Node> que;
	que.push({ 1,0 });
	visited[1] = 1;

	while (!que.empty()) {
		int cur = que.front().cur;
		int lev = que.front().lev;
		que.pop();

		if (cur == N) {
			ans = lev;
			break;
		}

		if (!isInside(cur)) continue;

		for (int i = 1; i <= map[cur]; i++) {
			if (cur + i <= N && visited[cur+i] == 0) {
				visited[cur + i] = 1;
				que.push({ cur + i,lev + 1 });
			}
		}
	}
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> map[i];

	bfs();

	cout << ans << endl;

	return 0;
}

