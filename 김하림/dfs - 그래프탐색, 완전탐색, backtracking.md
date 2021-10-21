dfs -> 그래프탐색, 완전탐색, backtracking

bfs -> 그래프탐색, 완전탐색, flood filed

flood filed -> 상하좌우로 하나씩 값이 증가할 때  특정 구역의 값 구하는 문제



섬 갯수 구하기

```c++
#include <iostream>
#include <queue>
using namespace std;

int map[5][5] = {
	1,0,0,1,0,
	0,0,1,0,0,
	0,0,0,0,0,
	0,1,1,1,0,
	1,0,1,0,0,
};
int y, x;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;

void island(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		map[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int n_y = y + dir[i][0];
			int n_x = x + dir[i][1];

			if (n_y < 0 || n_x < 0 || n_y >= 5 || n_x >= 5) continue;
			if (map[n_y][n_x] == 0) continue;
			map[n_y][n_x] = 0;
			q.push({ n_y,n_x });
		}
	}
	cnt++;
}

int main() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == 1)
				island(i, j);
		}
	}
	cout << cnt << endl;

	return 0;
}
```

```c++
#include <iostream>
#include <queue>
using namespace std;

int map[4][6] = {
	0,0,-1,-1,-1,-1,
	0,0,-1,0,0,-1,
	0,0,-1,0,0,-1,
	0,-1,-1,-1,-1,0
};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;
int bfs(int y, int x,int loc_y, int loc_x) {
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;

		q.pop();

		if (y == loc_y && x == loc_x) return map[y][x];

		for (int i = 0; i < 4; i++) {
			int n_y = y + dir[i][0];
			int n_x = x + dir[i][1];

			if (n_y < 0 || n_x < 0 || n_y >= 4 || n_x >= 6) continue;
			if (map[n_y][n_x] != 0) continue;
			map[n_y][n_x] = map[y][x] + 1;
			q.push({ n_y,n_x });
		}
	}
	
}

int main() {
	vector<pair<int, int>> wall;
	int backup[4][6];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == -1) wall.push_back({ i,j });
		}
	}
	int Min = 9999999;
	memcpy(backup, map, sizeof(map));
	for (int i = 0; i < wall.size() -1 ; i++) {
		for (int j = i + 1; j < wall.size(); j++) {
			map[wall[i].first][wall[i].second] = 0;
			map[wall[j].first][wall[j].second] = 0;
			int ret = bfs(3, 5, 0, 0);
			memcpy(map, backup, sizeof(map));
			if (Min > ret)
				Min = ret;
		}
	}
	

	cout << Min << endl;

	return 0;
}
```

벽 두개만 부셔서 공주 구하기



배달 최소시간 구하기

```c++
#include <iostream>
#include <queue>
using namespace std;

int map[4][6] = {
	0,0,0,2,1,0,
	-1,-1,0,0,-1,1,
	3,-1,-1,0,0,0,
	4,0,2,0,3,4,
};

struct node {
	int y;
	int x;
	int level;
};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;
int k = 1;
int used[4][6] = {};
int bfs(int y, int x) {
	queue<node> q;
	q.push({ y,x ,0});

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		if (k == 5) return now.level + 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 6) continue;
			if (map[ny][nx] == -1) continue;

			if (map[ny][nx] == k) {
				q.push({ ny,nx ,now.level + 1 });
				k++;
				continue;
			}
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			now.y = ny;
			now.x = nx;
			now.level = now.level + 1;
			q.push(now);
		}
	}
	
}

int main() {

	
	cout << bfs(0, 0) << endl;

	

	return 0;
}
```

내가 짜본 코드

```c++
	
#include<iostream>//   피자배달

#include<vector>

#include<cstring>
using namespace std;
int map[4][6] = {
0,0,0,2,1,0,
9,9,0,0,9,0,
3,9,9,0,0,0,
4,0,2,0,3,4,
};
struct node {
    int y; int x; int level;
};
int bfs(int starty, int startx, int targetN, intky, intkx)
{
    node queue[1000] = { starty,startx,0 };
    int head = 0;
    int tail = 1;
    int used[4][6] = { 0 };
    used[starty][startx] = 1;
    int direct[4][2] = { 0,1,0,-1,1,0,-1,0 };
    while (head != tail)
    {
        node now = queue[head++];
        for (int t = 0; t < 4; t++)
        {
            int dy = direct[t][0] + now.y;
            int dx = direct[t][1] + now.x;
            if (dy < 0 || dx < 0 || dy>3 || dx>5)continue;
            if (map[dy][dx] == 9)continue;
            if (used[dy][dx] == 1)continue;
            used[dy][dx] = 1;
            queue[tail++] = { dy,dx,now.level + 1 };
            if (map[dy][dx] == targetN) {
                *ky = dy;
                *kx = dx;
                return now.level + 1;
            }

    }
}
}

int main()
{
    int starty = 0;
    int startx = 0;
    int ky, kx;
    int targetN = 1;
    int cnt = 0;

while (1)
{
    int ret = bfs(starty, startx, targetN, &ky, &kx);
    if (ret == -1)break;
    cnt += ret;
    starty = ky;
    startx = kx;
    targetN++;
    if (targetN == 5)break;
}

cout << cnt;

return 0;
}
```

강사님 코드



안나와 엘사

```c++
#include<iostream>
using namespace std;
struct node {
    int ay, ax, by, bx;
    int level;
};
node queue[10000];
int head = 0, tail = 1;
int map[5][5] = {
    0,0,0,1,0,
    0,0,0,1,0,
    1,1,0,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
};
int used[5][5][5][5];
int direct[5][2] = {
    0,0,1,0,-1,0,0,-1,0,1
};
int main()
{
    int Min = 21e8;
    int a, b, c, d;
    cin >> a >> b >> c >> d;  
    queue[0] = { a,b,c,d };
    int result=-1;
    int flag = 0;
    while (head != tail)
    {
        node now = queue[head++];

        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                int ady = direct[y][0] + now.ay;
                int adx = direct[y][1] + now.ax;
                int bdy = direct[x][0] + now.by;
                int bdx = direct[x][1] + now.bx;
                if (ady < 0 || adx < 0 || bdy < 0 || bdx < 0)continue;
                if (ady > 4 || adx >4 || bdy >4 || bdx >4)continue;
                if (used[ady][adx][bdy][bdx] == 1)continue;
                if (map[ady][adx] == 1 || map[bdy][bdx] == 1)continue;
                used[ady][adx][bdy][bdx] = 1;
                queue[tail++] = { ady,adx,bdy,bdx,now.level + 1 };
                if (ady == bdy && adx == bdx)
                {
                    result = now.level + 1;
                    if (result < Min)Min = result;
                    
                }
            }
        }
    }

    cout << Min;


    return 0;
}
```

