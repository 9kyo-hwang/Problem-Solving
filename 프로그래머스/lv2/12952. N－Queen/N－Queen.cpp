#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N;
int cols[13];

bool promising(int level)
{
    for(int i = 1; i < level; i++)
    {
        if(cols[i] == cols[level]) return false;
        else if(level - i == abs(cols[level] - cols[i])) return false;
    }
    return true;
}

int queens(int level)
{
    if(!promising(level)) return 0;
    else if(level == N) return 1;
    else
    {
        int count = 0;
        for(int i = 1; i <= N; i++)
        {
            cols[level + 1] = i;
            count += queens(level + 1);
        }
        return count;
    }
}

int solution(int n) 
{
    N = n;
    return queens(0);
}