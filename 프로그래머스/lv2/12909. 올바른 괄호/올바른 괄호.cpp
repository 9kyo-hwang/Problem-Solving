#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for(const auto& c : s) {
        if(n < 0) break; // 음이 되는 경우는 발생할 수 없음(닫는 괄호가 먼저 나오거나 초과하는 경우)
        
        if(c == '(') n++;
        else if(c == ')') n--;
    }
    
    return n == 0;
}