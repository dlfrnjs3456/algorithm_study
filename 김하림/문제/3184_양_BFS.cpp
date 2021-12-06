#include <iostream>
#include <queue>
using namespace std;
#define MAX 251

int r, c;
char yard[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int o, v;
int sheep = 0, wolf = 0;

struct node {
	int y, x;
};
queue<node> q;

void bfs() {
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i][0];
			int nx = cx + dir[i][1];

			if (visited[ny][nx] || yard[ny][nx] == '#') continue;

			if (yard[ny][nx] == 'o') {
				q.push({ ny, nx });
				o++;
			}

			else if (yard[ny][nx] == 'v') {
				q.push({ ny,nx });
				v++;
			}
			else
				q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
	if (v < o) sheep += o;
	else wolf += v;
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
			if (!visited[i][j] && (yard[i][j] == 'o' || yard[i][j] == 'v')) {
				o = 0, v = 0;
				q.push({ i,j });
				if (yard[i][j] == 'o')
					o++;
				else if (yard[i][j] == 'v')
					v++;
				visited[i][j] = true;
				bfs();
			}
		}
	}
	cout << sheep << " " << wolf;

	return 0;
}