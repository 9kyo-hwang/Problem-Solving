#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string s) 
{
    int answer = s.length();
    for(int len = 1; len <= s.length() / 2; len++)
    {
        deque<string> dq;
        for(int i = 0; i < s.length(); i += len) 
            dq.emplace_back(s.substr(i, len));

        string str;
        while(!dq.empty())
        {
            string front = dq.front(); dq.pop_front();
            int cnt = 1;
            
            while(!dq.empty() && front == dq.front())
            {
                cnt += 1;
                dq.pop_front();
            }
            
            if(cnt > 1) str += to_string(cnt);
            str += front;
        }
        
        answer = min(answer, (int)str.length());
    }
    return answer;
}