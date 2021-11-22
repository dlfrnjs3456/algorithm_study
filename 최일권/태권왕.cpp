//태균이 점수 S, 상대 점수 T
// A -> 현재 점수 만큼 점수 획득 가능, 상대도 3점 얻음
//B -> 1점 얻는 연속 발차기
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
		//S와 T가 같아질 때 까지 최소 발차기 횟수
		int ans = kick();

		cout << ans << endl;
	}

	return 0;
}