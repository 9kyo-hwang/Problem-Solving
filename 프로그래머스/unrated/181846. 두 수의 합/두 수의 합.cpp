#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string solution(string a, string b) {
    deque<char> dq;
    int i = a.length() - 1, j = b.length() - 1;
    
    int carry = 0;
    while(i >= 0 && j >= 0) {
        int num = a[i] - '0' + b[j] - '0' + carry;
        dq.push_front(num % 10 + '0');
        carry = num / 10;
        i--, j--;
    }
    
    while(i >= 0) {
        int num = a[i] - '0' + carry;
        dq.push_front(num % 10 + '0');
        carry = num / 10;
        i--;
    }
    
    while(j >= 0) {
        int num = b[j] - '0' + carry;
        dq.push_front(num % 10 + '0');
        carry = num / 10;
        j--;
    }
    
    if(carry != 0)
        dq.push_front(carry + '0');

    return string{dq.begin(), dq.end()};
}