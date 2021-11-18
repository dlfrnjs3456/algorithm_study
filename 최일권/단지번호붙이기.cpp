#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int map[26][26] = {};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visited[26][26] = {};
int cnt = 0;
int isInside(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) return 0;
	return 1;
}
int lev[625] = {}; //25 * 25���̱� ������ �ִ� 625�� ����
				   // ���� �� �� ���� ����
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (!isInside(ny, nx) || visited[ny][nx] != 0) continue; //���� ���� 
		if (map[ny][nx] == 1) {//���� ���� ���
			visited[ny][nx] = 1;
			lev[cnt]++;// �� ���� ����
			dfs(ny, nx);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				dfs(i, j);
				cnt++;//���� üũ
			}
		}
	}

	sort(lev, lev + cnt);//������������ �����ϱ�

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << lev[i] + 1 << endl;
	}//���

	return 0;
}
