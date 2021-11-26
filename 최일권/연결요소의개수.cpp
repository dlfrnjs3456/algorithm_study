#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001] = {};
int visited[1001][100] = {};
int num_chk[1001] = {};
void dfs(int y, int x) {
	visited[y][x] = 1;
	visited[x][y] = 1;

	for (int i = 1; i <= N; i++) {
		if (map[x][i] == 1 && visited[x][i] == 0)
			dfs(x, i);
		if (map[i][y] == 1 && visited[i][y] == 0)
			dfs(i, y);
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (num_chk[a] == 0) num_chk[a] = 1;
		if (num_chk[b] == 0) num_chk[b] = 1;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visited[i][j]==0) {
				dfs(i, j);
				ans++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (num_chk[i] == 0) ans++;
	}

	cout << ans << endl;

	return 0;
}