#include <string>
#include <vector>
#include <cctype>

using namespace std;

int handleAlpha(const string &s, int &index) {
    switch(s[index]) {
        case 'z':  // 0
            index += 4;
            return 0;
        case 'o':  // 1
            index += 3;
            return 1;
        case 't':  // 2, 3
            if(s[index + 1] == 'w') {
                index += 3;
                return 2;
            } else if(s[index + 1] == 'h') {
                index += 5;
                return 3;
            }
        case 'f':  // 4, 5
            if(s[index + 1] == 'o') {
                index += 4;
                return 4;
            } else if(s[index + 1] == 'i') {
                index += 4;
                return 5;
            }
        case 's':  // 6, 7
            if(s[index + 1] == 'i') {
                index += 3;
                return 6;
            } else if(s[index + 1] == 'e') {
                index += 5;
                return 7;
            }
        case 'e':  // 8
            index += 5;
            return 8;
        case 'n':  // 9
            index += 4;
            return 9;
    }
}

int solution(string s) {
    int answer = 0;
    int index = 0;
    while(index < s.length()) {
        if(isdigit(s[index])) {
            answer = answer * 10 + (s[index++] - '0');
        } else {
            answer = answer * 10 + handleAlpha(s, index);
        }
    }
    return answer;
}