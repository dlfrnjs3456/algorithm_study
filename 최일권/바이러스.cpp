#include <iostream>
using namespace std;

int N, M;
int computer[101][101] = {};
int visited[101] = {};
int ans = 0;
void dfs(int start) {

	visited[start] = 1;

	for (int i = 1; i <= N; i++) {
		if (computer[start][i] == 1 && visited[i]==0) {
			ans++;
			dfs(i);
		}
	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		computer[a][b] = 1;
		computer[b][a] = 1;
	}

	dfs(1);

	cout << ans - 1<< endl;


	return 0;
}