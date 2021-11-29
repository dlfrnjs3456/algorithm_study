#include <iostream>
#include <queue>
using namespace std;
#define MAX 51
int n, m;
char ground[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
int wcnt = 0, lcnt = 0;

struct node {
	int y, x;
	int lev = 0;
	char board;
};
queue <node> q;
void bfs() {
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curLev = q.front().lev;
		char curBoard = q.front().board;
		q.pop();

		if (curBoard == '-') {
			for (int i = 0; i < m; i++) {
				int nextY = curY;
				int nextX = curX + 1;
				char nextBoard = ground[nextY][nextX];
				
				if (nextBoard == '-' && !visited[nextY][nextX]) {
					q.push({ nextY, nextX, curLev + 1, nextBoard });
					visited[nextY][nextX] = true;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				int nextY = curY + 1;
				int nextX = curX;
				char nextBoard = ground[nextY][nextX];

				if (nextBoard == '|' && !visited[nextY][nextX]) {
					q.push({ nextY, nextX, curLev + 1, nextBoard });
					visited[nextY][nextX] = true;
				}
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]){
				q.push({ i, j, 0, ground[i][j] });
				visited[i][j] = true;
				if (ground[i][j] == '-') wcnt++;
				else lcnt++;
				bfs();
				}
		}
	}
	cout << wcnt + lcnt;
}