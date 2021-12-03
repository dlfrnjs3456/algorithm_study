#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 101
using namespace std;
int N, L, R;
int map[MAX][MAX];
bool visited[MAX][MAX] = { 0 };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node {
	int y, x;
	int popul;
};
queue <node>q;
vector<node>v;
bool isInside(int a, int b) {
	if (0 <= a && a < N && 0 <= b && b < N)
		return true;
	else return false;
}

void bfs() {
	int cnt = 1;
	int sumPop = q.front().popul;
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curPop = q.front().popul;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];
			int diff = abs(map[curY][curX] - map[nextY][nextX]);

			if (!visited[nextY][nextX] && isInside(nextY, nextX)
				&& L <= diff && diff <= R) {
				q.push({ nextY, nextX, map[nextY][nextX] });
				v.push_back({ nextY, nextX, map[nextY][nextX] });
				visited[nextY][nextX] = true;
				cnt++;
				sumPop += map[nextY][nextX];
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		map[v[i].y][v[i].x] = sumPop / cnt;
	}
}


int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int day = 0;
	while (1) {
		int bfscnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.push_back({ i,j,map[i][j] });
					q.push({ i,j,map[i][j] });
					visited[i][j] = true;
					bfs();
					bfscnt++;
					while (!v.empty())
						v.pop_back();
				}
			}
		}
		if (bfscnt == N * N) {
			cout << day;
			break;
		}
		day++;
	}
	return 0;
}