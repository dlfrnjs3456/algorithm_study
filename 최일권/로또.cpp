#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int S[14] = {};
int used[14] = {};
vector<int> comb;
int K;
void lotto(int idx, int lev) {

	if (lev == 6) {
		int sz = comb.size();

		for (int i = 0; i < sz; i++)
			cout << comb[i] << " ";
		cout << endl;

		return;
	}

	for (int i = idx; i <= K; i++) {
		if (used[i] != 0) continue;
		used[i] = 1;
		comb.push_back(S[i]);
		lotto(i, lev + 1);
		comb.pop_back();
		used[i] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		cin >> K;

		memset(used, 0, sizeof(used));
		comb.clear();

		if (K == 0) break;

		for (int i = 1; i <= K; i++) cin >> S[i];

		lotto(1, 0);

		cout << "\n";
	}

	return 0;
}