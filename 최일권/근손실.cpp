#include <iostream>
using namespace std;

int N, K;
int used[9] = {};
int weight = 500;
int ans = 0;
int physic[9] = {};

void make_muscle( int lev) {

	if (weight < 500) return;

	if (lev == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		weight += (physic[i] - K);
		make_muscle(lev + 1);
		used[i] = 0;
		weight -= (physic[i] - K);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> physic[i];

	make_muscle(0);

	cout << ans << endl;

	return 0;
}