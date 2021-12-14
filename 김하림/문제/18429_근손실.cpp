#include <iostream>
using namespace std;
#define MAX 9

int n, k;
int arr[MAX];
bool visited[MAX] = { 0 };
int cnt = 0;
void dfs(int increase, int weight, int depth) {
	if (depth == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		if (weight - k + arr[i] < 500) continue;
		visited[i] = true;
		dfs(arr[i], weight - k + arr[i], depth + 1);
		visited[i] = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dfs(0, 500, 0);
	cout << cnt;
	return 0;
}