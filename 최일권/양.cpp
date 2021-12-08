#include <iostream>
using namespace std;

int R, C;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

char map[251][251] = {};
int visited[251][251] = {};
int total_sheep = 0;
int total_wolf = 0;

int sheep = 0;
int wolf = 0;

int isInside(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C) return 0;

	return 1;
}

void dfs(int y, int x) {
	visited[y][x] = 1;

	if (map[y][x] == 'o') sheep++;
	if (map[y][x] == 'v') wolf++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (!isInside(ny, nx) || visited[ny][nx] != 0 || map[ny][nx] == '#') continue;
		dfs(ny, nx);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') total_sheep++;
			if (map[i][j] == 'v') total_wolf++;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && visited[i][j] == 0) {
				wolf = 0;
				sheep = 0;
				dfs(i, j);

				if (sheep > wolf) {
					total_wolf -= wolf;
				}
				else {
					total_sheep -= sheep;
				}

			}
		}
	}

	cout << total_sheep << " " << total_wolf << endl;

	return 0;
}