#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    string ans;
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            ans += s[i];
        else if (s[i] == 'z') {
            ans += '0';
            i += 3;
        }
        else if (s[i] == 'o') {
            ans += '1';
            i += 2;
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                ans += '2';
                i += 2;
            }
            else {
                ans += '3';
                i += 4;
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] == 'o') {
                ans += '4';
                i += 3;
            }
            else {
                ans += '5';
                i += 3;
            }
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                ans += '6';
                i += 2;
            }
            else {
                ans += '7';
                i += 4;
            }
        }
        else if (s[i] == 'e') {
            ans += '8';
            i += 4;
        }
        else if (s[i] == 'n') {
            ans += '9';
            i += 3;
        }
    }
    answer = stoi(ans);
    cout << answer;
    return answer;
}

int main() {
    string str = "one4seveneight";
    solution(str);
    return 0;
}