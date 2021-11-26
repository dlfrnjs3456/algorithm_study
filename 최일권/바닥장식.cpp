#include <iostream>
#include <queue>
using namespace std;

int N, M;
char ground[51][51] = {};
int visited[51][51] = {};
int ans = 0;
struct Node {
	int y, x;
};

int isInside(int y, int x) {
	if (y <= 0 || y > N || x <= 0 || x > M) return 0;
	return 1;
}

void cnt_wood() {

	for(int y=1;y<=N;y++){
		for (int x = 1; x <= M; x++) {
			if (visited[y][x] != 0) continue;

			if (ground[y][x] == '|' && visited[y][x] == 0) {
				ans++;
				visited[y][x] = 1;

				int ny = y + 1;
				if (ground[ny][x] == '|' && visited[ny][x] == 0 && isInside(ny, x)) {
					visited[ny][x] = 1;
					while (1) {
						ny++;
						if (!isInside(ny, x) || visited[ny][x] != 0 || ground[ny][x] != '|') break;
						visited[ny][x] = 1;
					}
				}
			}
			else if (ground[y][x] == '-' && visited[y][x] == 0) {
				ans++;
				visited[y][x] = 1;

				int nx = x + 1;
				if (ground[y][nx] == '-' && visited[y][nx] == 0 && isInside(y, nx)) {
					visited[y][nx] = 1;
					while (1) {
						nx++;
						if (!isInside(y, nx) || visited[y][nx] != 0 || ground[y][nx] != '-') break;
						visited[y][nx] = 1;
					}
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ground[i][j];
		}
	}

	cnt_wood();

	cout << ans << endl;

	return 0;
}