#include <iostream>
#include <queue>
using namespace std;

int N, M;
int box[1001][1001] = {};
int visited[1001][1001] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int isInside(int y, int x) {
	if (y < 0 || y >= M || x < 0 || x >= N) return 0;

	return 1;
}
struct Node {
	int y, x;
	int lev = 0;
};

int ans = 0;
queue<Node> que;

void bfs() {
	
	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		int lev = que.front().lev; //토마토가 몇번째 익고 있는지 체크
		que.pop();
		ans = lev;

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (!isInside(ny, nx) || visited[ny][nx] != 0 || box[ny][nx] == -1) continue;

			if (box[ny][nx] == 0) { //안익은 토마토일 때만 시행
				visited[ny][nx] = 1;
				que.push({ ny,nx,lev + 1 }); 
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				que.push({ i,j,0 });//토마토가 한 번에 여러개 익은 경우의 수를 체크하기 위해 두 개의 좌표에서 한번에 시행하기 위한 queue 저장
				visited[i][j] = 1;
			}
		}
	}

	bfs();

	int flag = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] != -1 && visited[i][j] == 0) {//토마토가 완전히 익지 않은 경우 체크
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	
	if (flag) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
