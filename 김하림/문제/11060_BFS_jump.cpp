#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int n;
bool visited[MAX] = { 0 };
int maze[MAX] = { 0 };

struct node {
	int index;
	int num;
	int level = 0;
};

int bfs() {
	queue<node> q;
	int min = MAX;
	int temp;
	q.push({ 1, maze[1],0 });
	visited[1] = true;
	
	while (!q.empty()) {
		int curIn = q.front().index;
		int curNum = q.front().num;
		int lev = q.front().level;
		q.pop();
		if (curIn == n) {
			cout << lev;
			return 0;
		}

		for (int i = 1; i <= curNum; i++) {
			int nextIn = curIn + i;
			int nextNum = maze[nextIn];

			if (!visited[nextIn]&&nextIn<=n) {
				visited[nextIn] = true;
				q.push({ nextIn, nextNum, lev + 1 });
				temp = nextIn;
			}
		}
	}

	cout << -1;
	return 0;
}

//1 2 0 3 1

//1
//2
//0 3
//1

//1 0 0 0 0 3
//1
//0





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> maze[i];
	}
	bfs();

	return 0;
}