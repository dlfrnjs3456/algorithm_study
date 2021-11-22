//�� ¡�˴ٸ��� �����ִ� �����ŭ ������ �ִ� ���� �̵� ����
//a��°���� b��°�� ������ �Ѵ�.
#include <iostream>
#include <queue>
using namespace std;

int N;
int a, b;
int stone[10001] = {};
int visited[10001] = {};
struct Node {
	int cur;
	int lev;
};

int frog_jump() {
	queue<Node> que;
	que.push({ a ,0});
	int ans = -1;
	visited[a] = 1;
	while (!que.empty()) {
		int cur = que.front().cur;
		int lev = que.front().lev;
		que.pop();

		if (cur == b) {
			ans = lev;
			break;
		}

		if (cur < b) {
			for (int i = 1; i <= N; i++) {
				int next = cur + (stone[cur] * i);

				if (next >= 1 && next <= N && visited[next] == 0) {
					visited[next] = 1;
					que.push({ next,lev + 1 });
				}
			}
		}
		else if(cur > b) {
			for (int i = 1; i <= N; i++) {
				int next = (cur - stone[cur] * i);

				if (next >= 1 && next <= N && visited[next] == 0) {
					visited[next] = 1;
					que.push({ next,lev + 1 });
				}
			}
		}
	}

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stone[i];
	}
	cin >> a >> b;

	int ans = frog_jump();

	cout << ans << endl;

	return 0;
}