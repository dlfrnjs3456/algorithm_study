#include <iostream>
#include <string>
#include <stack>
using namespace std;

int vps(string s) {
	stack <int> sta;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			sta.push(1);
		else {
			if (sta.empty()) {
				cout << "NO" << endl;
				return 0;
			}
			else
				sta.pop();
		}
	}
	if (sta.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

int main() {
	int t;
	string st;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> st;
		vps(st);
	}
}
