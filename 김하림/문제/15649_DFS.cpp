#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9] = { 0 };

void dfs(int cnt) { //ÇöÀç À§Ä¡
	if (cnt == m) { 
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				arr[cnt] = i;
				visited[i] = true;
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}
