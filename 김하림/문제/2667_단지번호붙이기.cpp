#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 26
int n;
bool visited[MAX][MAX] = { 0 };
int map[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node {
	int y, x;
};
queue <node> q;
vector <int> v;
void bfs() {
	int house = 1;
	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i][0];
			int nextX = curX + dir[i][1];

			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n
				&& !visited[nextY][nextX] && map[nextY][nextX] == 1) {
				q.push({ nextY, nextX });
				visited[nextY][nextX] = true;
				house++;
			}
		}
	}
	v.push_back(house);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = true;
				bfs();
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}