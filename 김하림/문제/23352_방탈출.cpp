#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define MAX 51

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int maxLev = 0;
int last = 0;
int sum = 0;

bool isInside(int y, int x) {
	if (0 <= y && y < n && 0 <= x && x < m) return true;
	else return false;
}

struct node {
	int y, x;
	int lev = 0;
	int num;
};
queue<node> q;

void bfs() {
	int first = q.front().num;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int clev = q.front().lev;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (visited[ny][nx] || !isInside(ny, nx) || map[ny][nx] == 0) continue;
			q.push({ ny, nx, clev + 1 });
			visited[ny][nx] = true;
			if (maxLev < clev + 1) {
				maxLev = clev + 1;
				last = map[ny][nx];
				sum = first + last;
			}
			else if (maxLev == clev + 1) {
				if (sum < first + map[ny][nx]) {
					last = map[ny][nx];
					sum = first + last;
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			if (map[i][j] == 0) continue;
			q.push({ i,j,0,map[i][j] });
			visited[i][j] = true;
			int first = map[i][j];
			bfs();
		}
	}
	cout << sum;

	//가장긴걸 찾아야됨
	//first+last
	//길이가 같으면 그 때 비교

	return 0;
}