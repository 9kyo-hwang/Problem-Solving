#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_satisfy(const string& data, const string& friends)
{
    char src = data[0], dst = data[2], op = data[3];
    int interval = data[4] - '0';

    int src_idx = 0, dst_idx = 0;
    for (int i = 0; i < friends.length(); i++)
    {
        if (friends[i] == src)
        {
            src_idx = i;
        }
        else if (friends[i] == dst)
        {
            dst_idx = i;
        }
    }
    
    int result = abs(dst_idx - src_idx) - 1;

    if (op == '<') return result < interval;
    else if (op == '>') return result > interval;
    else if (op == '=') return result == interval;
}

int solution(int n, vector<string> data) 
{
    string friends = "ACFJMNRT";
    int answer = 0;
    do
    {
        bool flag = true;
        for(const string &str : data)
        {
            if(!is_satisfy(str, friends))
            {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}