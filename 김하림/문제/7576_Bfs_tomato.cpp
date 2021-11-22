#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

bool visited[MAX][MAX] = { 0 };
int tomato[MAX][MAX];
int m, n;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int day;
int lev;
struct tom {
	int y = 0;
	int x = 0;
	int level = 0;
};
queue <tom> q;

void bfs() {
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		lev = q.front().level;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n
				&& !visited[nextY][nextX] && tomato[nextY][nextX] == 0) {
				q.push({ nextY,nextX,lev + 1 });
				visited[nextY][nextX] = true;
				tomato[nextY][nextX] = 1;
			}
		}
	}
	day = lev;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i,j,0 });
				visited[i][j] = true;
			}
		}
	}
	int zero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				zero++;
			}
		}
	}
	if (zero == 0) {
		cout << zero;
		return 0;
	}

	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day;
	return 0;
}