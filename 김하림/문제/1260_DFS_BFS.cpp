#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int N, M, V;

int graph[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}

void bfs(int v) {
	queue <int> q;
	q.push(v);
	visited[v] = 1;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}

}

int main() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(V);

	for (int i = 0; i < MAX; i++)
		visited[i] = 0;
	cout << endl;

	bfs(V);
	return 0;
}