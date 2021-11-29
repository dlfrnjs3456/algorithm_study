#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> memo;

int chk_num(int num) {

	int start = 0;
	int end = N - 1;
	int mid = (start + end) / 2;

	while (start <= end) {
		if (memo[mid] == num) return 1;
		else if (num < memo[mid])end = mid - 1;
		else if (num > memo[mid]) start = mid + 1;
		mid = (start + end) / 2;
	}

	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> N;
		memo.clear();
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			memo.push_back(num);
		}

		sort(memo.begin(), memo.end());

		cin >> M;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			if (chk_num(num)) cout << "1\n";
			else cout << "0\n";
		}
	}


	return 0;
}