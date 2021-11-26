#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
#define MAX_ 100001

int N;
int parent[100001] = {};
vector<int> vec[100001];
int visited[100001] = {};
int root = 1;

void dfs(int cur) {

	visited[cur] = 1;

	int sz = vec[cur].size();
	for (int i = 0; i < sz; i++) {
		if (visited[vec[cur][i]] != 0) continue;
		parent[vec[cur][i]] = cur;
		dfs(vec[cur][i]);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(root);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}


	return 0;
}