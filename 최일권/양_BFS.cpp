#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[251][251] = {};
int visited[251][251] = {};

int total_sheep = 0;
int total_wolf = 0;

int sheep = 0;
int wolf = 0;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int isInside(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C) return 0;
	return 1;
}

struct Node {
	int y, x;
};

void bfs(int y, int x) {
	queue<Node> que;
	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {
		y = que.front().y;
		x = que.front().x;
		que.pop();

		if (map[y][x] == 'o') sheep++;
		if (map[y][x] == 'v') wolf++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (map[ny][nx] == '#' || !isInside(ny, nx) || visited[ny][nx] != 0) continue;
			visited[ny][nx] = 1;
			que.push({ ny,nx });
		}
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
				sheep = 0;
				wolf = 0;
				bfs(i, j);

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