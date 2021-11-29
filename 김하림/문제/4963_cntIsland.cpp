#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

int h, w, cnt = 0;
int map[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1} };
struct node {
	int y, x;
	int lev = 0;
};
queue<node> q;

bool isInside(int a, int b) {
	if (0 <= a && a < h && 0 <= b && b < w)
		return true;
	else false;
}
void clear() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
	w = -1;
	h = -1;
	cnt = 0;
}

void bfs() {
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curL = q.front().lev;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (isInside(nextY, nextX) && !visited[nextY][nextX] &&
				map[nextY][nextX] == 1) {
				q.push({ nextY, nextX, curL + 1 });
				visited[nextY][nextX] = true;
			}
		}
	}
	cnt++;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (;;) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					q.push({ i, j, 0 });
					visited[i][j] = true;
					bfs();
				}
			}
		}
		cout << cnt << endl;
		clear();
	}
}