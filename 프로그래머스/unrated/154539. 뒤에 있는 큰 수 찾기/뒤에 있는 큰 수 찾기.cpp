#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int N = numbers.size();
    vector<int> answer(N);
    stack<int> s;
    
    for(int i = N - 1; i >= 0; i--) {
        int top = -1;
        while(true) {
            if(s.empty() || s.top() > numbers[i]) {
                if(!s.empty())
                    top = s.top();
                
                s.emplace(numbers[i]);
                answer[i] = top;
                break;
            }
            s.pop();
        }
    }
    
    return answer;
}