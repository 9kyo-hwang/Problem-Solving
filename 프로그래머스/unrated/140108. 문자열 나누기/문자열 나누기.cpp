#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    int a = 1, b = 0;
    for(int i = 1; i < s.length(); i++) {
        s[i] == x ? a += 1 : b += 1;
        if(a == b) {
            answer += 1;
            i += 1;
            x = s[i];
            a = 1;
            b = 0;
        }
    }
    if(x != '\0')
        answer++;
    return answer;
}