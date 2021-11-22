//�±��� ���� S, ��� ���� T
// A -> ���� ���� ��ŭ ���� ȹ�� ����, ��뵵 3�� ����
//B -> 1�� ��� ���� ������
#include <iostream>
#include <queue>
using namespace std;

int point[101] = {};
int visited[101] = {};
int C, S, T;

struct Node {
	int score;
	int enemy;
	int lev = 0;
};

int kick() {
	queue<Node> que;
	que.push({ S,T,0});
	visited[S] = 1;
	int ans = 0;

	while (!que.empty()) {
		int score = que.front().score;
		int enemy = que.front().enemy;
		int lev = que.front().lev;
		ans = lev;
		que.pop();

		if (score == enemy) break;
		
	
		int ns = 2*score;
		int nT = enemy + 3;

		if (ns <= nT ) {
			que.push({ ns,nT,lev + 1 });
		}

		ns = score + 1;

		if (ns <= enemy ) {
			que.push({ ns,enemy,lev + 1 });
		}
	}

	return ans;
}

int main() {

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> S >> T;
		//S�� T�� ������ �� ���� �ּ� ������ Ƚ��
		int ans = kick();

		cout << ans << endl;
	}

	return 0;
}