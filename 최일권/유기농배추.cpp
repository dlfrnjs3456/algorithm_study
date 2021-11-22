#include <iostream>
#include <memory.h>
using namespace std;

int N, M, K;
int map[51][51] = {};
int visited[51][51] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int isInside(int y, int x) {
	if(y<0 || y>N || x<0 || x>M) return 0;
	return 1;
}

void dfs(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		
		if (!isInside(ny, nx)) continue;

		if (visited[ny][nx] == 0 && map[ny][nx] == 1) {
			dfs(ny, nx);
		}
	}
}

int main() {
	int tc;

	cin >> tc;

	while (tc--) {

		int cnt = 0;

		cin >> M >> N >> K;

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					visited[i][j] = 1;
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

	}
	return 0;
}