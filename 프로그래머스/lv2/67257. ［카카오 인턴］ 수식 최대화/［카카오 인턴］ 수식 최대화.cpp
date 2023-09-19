#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const string operators[] = 
{
    "+-*",
    "+*-",
    "-+*",
    "-*+",
    "*+-",
    "*-+",
};

ll solution(string expression) 
{
    vector<ll> nums;
    vector<char> opers;
    
    string tmp;
    for(const char &ch : expression)
    {
        if(isdigit(ch)) tmp += ch;
        else
        {
            nums.emplace_back(stol(tmp));
            opers.emplace_back(ch);
            tmp.clear();
        }
    }
    nums.emplace_back(stol(tmp)); // 수식 끝 마지막 숫자 추가
    
    ll answer = 0;
    for(const auto &ops : operators)
    {
        vector<ll> v1(nums.begin(), nums.end());
        vector<char> v2(opers.begin(), opers.end());
        for(const auto &op : ops)
        {
            int i = 0;
            while(i < v2.size())
            {
                char oper = v2[i];
                if(op != oper)
                {
                    i++;
                    continue;
                }
                
                // 계산
                if(oper == '+') v1[i] += v1[i + 1];
                else if(oper == '-') v1[i] -= v1[i + 1];
                else if(oper == '*') v1[i] *= v1[i + 1];
                
                v1.erase(v1.begin() + (i + 1)); // 다음 숫자 삭제
                v2.erase(v2.begin() + i); // 현재 연산자 삭제
            }
        }
        
        answer = max(answer, abs(v1[0]));
    }
    
    return answer;
}