```c++
#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <cmath>
using namespace std;
//1,2,3,4,5,6,7,8,9 말 중 
//1~4등의 말의 합이 10 이하인 경우 몇 가지인지 출력

int cnt = 0;
int used[10] = {};
void select(int lev, int sum_) {

	if (sum_ > 10) return;

	if (lev == 4) {
		cnt++;
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (used[i] == 1) continue;
		used[i]= 1;
		select(lev + 1, sum_ + i);
		used[i] = 0;
	}

}

int main() {
	
	select(0,0);

	cout << cnt << endl;

	return 0;
}
```



```c++
#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <cmath>
using namespace std;

int dir[3][2] = { {1,-1},{1,0},{1,1} };
int sum = 0;
int max_ = -99999999999;
int isInside(int y, int x) {
	if (y < 0 || y>4 || x < 0 || x>3)
		return 0;
	return 1;
}
int map[5][4] = {
	3,2,4,1,
	0,1,0,5,
	2,0,3,0,
	5,4,0,2,
	2,5,0,3,
};

void drunken(int y, int x) {

	if (max_ < sum) {
		max_ = sum;
	}

	for (int i = 0; i < 3; i++) {
		int n_y = y + dir[i][0];
		int n_x = x + dir[i][1];

		if (isInside(n_y, n_x)) {
			sum += map[n_y][n_x];
			drunken(n_y, n_x);
			sum -= map[n_y][n_x];
		}
	}
}


int main() {
	
	for (int i = 0; i < 4; i++) {
		sum = 0;
		sum += map[0][i];
		drunken(0,i);
	}
	cout << max_ << endl;
	return 0;
}
```

