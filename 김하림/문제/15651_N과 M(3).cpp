#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool visited[8] = { 0 };
int arr[1000000] = { 0 };

void dfs(int depth) {
	if (depth == m) {

		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[depth] = i;
		dfs(depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0);
	return 0;
}