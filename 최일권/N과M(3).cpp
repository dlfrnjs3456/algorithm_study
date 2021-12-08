#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> path;

void N_M(int lev) {

	if (lev == M) {
		for (int i = 0; i < path.size(); i++)
			printf("%d ", path[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		path.push_back(i);
		N_M(lev + 1);
		path.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	scanf("%d %d", &N, &M);

	N_M(0);

	return 0;
}