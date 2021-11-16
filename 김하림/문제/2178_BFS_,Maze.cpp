#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
using namespace std;

int N, M;
int dir[4][2] = { {0,1}, {0,-1},{1,0},{-1,0 } };
int maze[MAX][MAX];
bool visited[MAX][MAX] = { 0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
				maze[ny][nx] = maze[y][x] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	

	bfs();
	cout << maze[N - 1][M - 1];
	return 0;
}