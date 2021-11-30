#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 1000001
int t, n, m;


int binarySearch(int ans[], int key) {
	int start = 0;
	int end = n - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (key < ans[mid])
			end = mid - 1;
		else if (ans[mid] < key)
			start = mid + 1;
		else return mid;
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer[MAX];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> answer[j];
		}
		sort(answer, answer + n);

		cin >> m;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			if (binarySearch(answer, num) != -1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		memset(answer, 0, sizeof(answer));
	}
	return 0;
}