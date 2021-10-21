큐(Queue)

-> FIFO(First in First out)

-> 보통 구현은 배열과 링크드 리스트로 구현

-> 하지만 STL로 잘 되어있기 때문에 굳이 구현할 필요는 없다



stack을 활용한 커서와 키보드 입력 및 삭제 구현

예를 들어 3AB<<>Qd 라는 명령어가 들어오면

3AQ가 출력되어야 함

```c++
#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> str;
	stack<char> temp;
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{

		if (input[i] == '<')
		{
			if (i != 0 && !str.empty()) {
				temp.push(str.top());
				str.pop();
			}
			continue;
		}
		if (input[i] == '>')
		{
			if (!temp.empty()) {
				str.push(temp.top());
				temp.pop();
			}
			continue;

		}
		if (input[i] == 'd')
		{
			if(!temp.empty())
				temp.pop();
			continue;
		}
		str.push(input[i]);

	}

	if (!str.empty())
	{
		stack<char> save;
		while (!str.empty())
		{
			save.push(str.top());
			str.pop();
		}
		while(!save.empty())
		{
			cout << save.top();
			save.pop();
		}
	}

	if (!temp.empty())
	{
		while (!temp.empty())
		{
			cout << temp.top();
			temp.pop();
		}
	}


	return 0;
}
```



G,A,T,R 네 사람이 있을 때, 5번째 지목될 때 마다 죽이고 마지막 한 명 출력하기

```c++
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	queue<char> que;
	int cnt = 1;

	que.push('G');
	que.push('A');
	que.push('T');
	que.push('R');
	
	while (1)
	{
		if (que.size() == 1)
			break;
		if(cnt!=5)
			que.push(que.front());
		if (cnt == 5)
			cnt = 0;
		que.pop();
		cnt++;
	}

	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	return 0;
}
```



```c++
#include <iostream>
#include <string>
using namespace std;

string str = "ABCDEFGH";
int used[100] = { 0 };

int nextPer(int idx)
{
    for (int i = idx + 1; i < str.length() * 2; i++) {
        int tx = i % str.length();
        if (used[tx] == 1) continue;
        return tx;
    }
    return 0;
}

int selectDie(int idx)
{
    //다섯번째 사람을 선택

    for (int i = 0; i < 5; i++) {
        idx = nextPer(idx);
    }

    return idx;
}

int main()
{
    int cnt = str.length();
    int idx = -1;

    while (cnt != 1) {
        idx = selectDie(idx);
        used[idx] = 1;
        cnt--;
    }

    for (int i = 0; i < str.length(); i++) {
        if (used[i] == 0) {
            cout << str[i] << endl;
            break;
        }
    }
    

    return 0;
}
```



2020카카오 겨울 인턴십 인형뽑기

```c++
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> mapst[6];
stack<int> result;
stack<int> temp;

void go(vector<vector<int>> map, vector<int> moves)
{
    //go 함수를 완성
    //출력결과 : (4)4 2 4 
                //터진개수와 쌓아둔 개수를 출력

    //1. 2차원배열 map을 mapst에 넣기
    for (int x = 0; x < 5; x++) {
        for (int y = 4; y >= 0; y--) {

            if (map[y][x] == 0) break;
            mapst[x + 1].push(map[y][x]);
        }
    }


    //2. move 하나씩 수행 result에 push

    int cnt = 0;
    for (int i = 0; i < moves.size(); i++) {

        int idx = moves[i];
        if (mapst[idx].size() == 0) continue;
        int ret = mapst[idx].top();
        mapst[idx].pop();

        if (result.size() > 0 && result.top() == ret) {
            result.pop();
            cnt += 2;
        }
        else {
            result.push(ret);
        }
    }

    while (!result.empty())
    {
        temp.push(result.top());
        result.pop();
    }

    cout << cnt << " ";
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
}

int main()
{
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    vector<vector<int>> map = {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1},
    };

    go(map, moves);

    return 0;
}
```

강사님 코드



```c++
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void go(vector<vector<int>> map, vector<int> moves)
{
	//go 함수를 완성
	//출력결과 : (4)4 2 4 
				//터진개수와 쌓아둔 개수를 출력
	stack<int> box;
	int idx = 0;
	int cnt = 0;
	
	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			int num = map[j][moves[i] - 1];
			map[j][moves[i] - 1] = 0;

			if (num != 0)
			{
				if (box.empty()) {
					box.push(num);
					break;
				}
				else
				{
					if (box.top() == num)
					{
						cnt += 2;
						box.pop();
						break;
					}
					else {
						box.push(num);
						break;
					}
				}
			}
		}
	}

	stack<int> ans;
	while (!box.empty())
	{
		ans.push(box.top());
		box.pop();
	}
	cout << "(" << cnt << ")";
	while (!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}

int main()
{
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	vector<vector<int>> map = {
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1},
	};

	go(map, moves);

	return 0;
}
```

내 코드