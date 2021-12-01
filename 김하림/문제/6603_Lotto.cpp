#include <iostream>
using namespace std;
#define MAX 13
int k;
bool visited[MAX] = { 0 };
int arr[MAX];
int lotto[6];


void dfs(int index, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << lotto[i] << " ";
		cout << endl;
	}
	else {
		for (int i = index; i < k; i++) {
			if (!visited[i]) {
				lotto[depth] = arr[i];
				visited[i] = true;
				dfs(i + 1, depth + 1);
				visited[i] = false;
			}

		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (;;) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << endl;
	}
	return 0;
}