#include <iostream>
#include <queue>
#define MAX 10001
using namespace std;
int n, a, b;
int arr[MAX] = { 0 };
bool visited[MAX] = { false };

struct node {
	int num, idx;
	int lev = 0;
};

void bfs() {
	int min = MAX + 1;
	queue<node> q;
	q.push({ arr[a], a, 0 });
	visited[a] = true;

	while (!q.empty()) {
		int curNum = q.front().num;
		int curIdx = q.front().idx;
		int curLev = q.front().lev;
		q.pop();
		
		
		int start = (1-curIdx)/curNum;
		int end = (n - curIdx) / curNum;
		for (int i = start; i <= end; i++) {
			int nextIdx = curIdx + curNum * i;
			int nextNum = arr[nextIdx];

			if (!visited[nextIdx]) {
				q.push({ nextNum, nextIdx, curLev + 1 });
				visited[nextIdx] = true;
				if (nextIdx == b) {
					if (min > curLev + 1)
						min = curLev + 1;
				}
			}
		}
	}
	if (min == MAX + 1)
		cout << -1;
	else 	cout << min;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}

	cin >> a >> b;

	bfs();
	return 0;
}