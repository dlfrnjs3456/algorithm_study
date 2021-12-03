#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

bool visited[6][6] = { 0 };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<string> map;

struct node {
    int y, x;
    int lev = 0;
};
queue <node> q;

bool isInside(int a, int b) {
    if (0 <= a && a < 5 && 0 <= b && b < 5)
        return true;
    else return false;
}

int bfs() {
    while (!q.empty()) {
        int curY = q.front().y;
        int curX = q.front().x;
        int curLev = q.front().lev;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if (isInside(nextY, nextX) && !visited[nextY][nextX]) {
                if (map[nextY][nextX] == 'O' && curLev < 2) {
                    //cout<<"push : "<<nextY<<" "<<nextX<<" "<<curLev+1<<endl;
                    q.push({ nextY, nextX, curLev + 1 });
                }
                else if (map[nextY][nextX] == 'P' && curLev < 2) {
                    //cout<<"P : "<<curY<<" "<<curX<<" "<<nextY<<" "<<nextX<<endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {
        int ans = 1;
        memset(visited, false, sizeof(visited));
        map = places[i];
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    q.push({ j, k, 0 });
                    visited[j][k] = true;
                    ans *= bfs();
                    //cout<<"ans: "<<ans<<endl;
                }
            }
        }
        //cout<<endl;
        answer.push_back(ans);
    }

    return answer;
}