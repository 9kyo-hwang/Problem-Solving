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
        int i = 0;
        queue<string> q;
        while(i < s.length())
        {
            q.emplace(s.substr(i, len));
            i += len;
        }
        
        string str;
        while(!q.empty())
        {
            string front = q.front(); q.pop();
            int cnt = 1;
            
            while(!q.empty() && front == q.front())
            {
                cnt += 1;
                q.pop();
            }
            
            if(cnt > 1) str += to_string(cnt);
            str += front;
        }
        
        answer = min(answer, (int)str.length());
    }
    return answer;
}