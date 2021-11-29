#include <iostream>
#include <memory.h>
using namespace std;

int w, h;
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
int map[51][51] = {};
int visited[51][51] = {};

int isInside(int y, int x) {
	if (y<1 || y>h || x<1 || x>w) return 0;
	return 1;
}

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (!isInside(ny, nx) || visited[ny][nx] != 0) continue;

		if (map[ny][nx] == 1) {
			dfs(ny, nx);
		}
	}
}

int main() {

	while (1) {
		cin >> w >> h;

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));

		if (w == 0 && h == 0) break;

		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				cin >> map[y][x];
			}
		}

		int ans = 0;
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				if (map[y][x] == 1 && visited[y][x] == 0) {
					dfs(y, x);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}