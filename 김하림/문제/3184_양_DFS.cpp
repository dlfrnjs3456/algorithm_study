#include <iostream>
using namespace std;
#define MAX 251

int r, c;
char yard[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
int sheep = 0, wolf = 0;
int o, v;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		
		if (visited[ny][nx] || yard[ny][nx] == '#') continue;
		if (yard[ny][nx] == 'o')
			o++;
		else if (yard[ny][nx] == 'v')
			v++;
		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> yard[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			o = 0, v = 0;
			if (!visited[i][j] && (yard[i][j] == 'o' || yard[i][j] == 'v')) {
				if (yard[i][j] == 'o') o++;
				else v++;
				visited[i][j] = true;
				dfs(i, j);
				if (o > v) sheep += o;
				else wolf += v;
			}
		}
	}
	cout << sheep << " " << wolf;

	return 0;
}