#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string answer = "";
    int minlen = min(a.length(), b.length());
    
    int up = 0;
    for(int i = 0; i < minlen; i++) {
        int num = (a[i] - '0') + (b[i] - '0') + up;
        answer.push_back((num % 10) + '0');
        up = num / 10;
    }
    
    if(a.length() < b.length()) {
        for(auto i = minlen; i < b.length(); i++) {
            int num = (b[i] - '0') + up;
            answer.push_back((num % 10) + '0');
            up = num / 10;
        }
    } else if(a.length() > b.length()) {
        for(auto i = minlen; i < a.length(); i++) {
            int num = (a[i] - '0') + up;
            answer.push_back((num % 10) + '0');
            up = num / 10;
        }
    }
    
    if(1 <= up && up <= 9)
        answer.push_back(up + '0');
    
    reverse(answer.begin(), answer.end());
    return answer;
}