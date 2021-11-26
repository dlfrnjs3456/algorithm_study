#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

bool visited[MAX][MAX] = { 0 };
int ground[MAX][MAX] = { 0 };
int m, n;
int cnt = 0;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node {
	int y, x;
};
queue<node> q;
void bfs() {
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m
				&& ground[nextY][nextX] == 1 && !visited[nextY][nextX]) {
				q.push({ nextY,nextX });
				visited[nextY][nextX] = true;
			}
		}
	}
	cnt++;
}
void clear() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = 0;
			ground[i][j] = 0;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			ground[b][a] = 1;
		}


		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				cout << ground[x][y] << " ";
			}
			cout << endl;
		}

		for (int s = 0; s < n; s++) {
			for (int r = 0; r < m; r++) {
				if (ground[s][r] == 1&&!visited[s][r]) {
					q.push({ s,r });
					visited[s][r] = true;
					bfs();
				}
			}
		}

		cout << cnt;
		clear();
	}
}