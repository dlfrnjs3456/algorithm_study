#include <iostream>
#include <queue>
using namespace std;
#define MAX 101
bool visited[MAX] = { 0 };
int graph[MAX][MAX] = { 0 };
int n, m;

void bfs() {
	int ans = -1;
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		ans++;

		for (int i = 1; i <= n; i++) {
			int next = i;
			if (graph[current][next] == 1 && !visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	bfs();
}