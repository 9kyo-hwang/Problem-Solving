#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    vector<int> stack;
    for(int i = 0; i < number.length(); i++) {
        int num = number[i] - '0';
        while(true) {
            if(stack.empty() || stack.back() >= num || k <= 0) {
                stack.emplace_back(num);
                break;
            }
            stack.pop_back();
            k--;
        }
    }
    
    string answer = "";
    for(int i = 0; i < stack.size() - k; i++)
        answer += stack[i] + '0';
    return answer;
}