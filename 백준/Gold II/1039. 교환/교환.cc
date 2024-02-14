#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

int N, K, M;
unordered_set<int> Visited[11];

int DFS(int Num = N, int Depth = 0)
{
    if(Visited[Depth].find(Num) != Visited[Depth].end())
    {
        return -1;
    }
    else if(Depth == K)
    {
        return Num;
    }
    else
    {
        Visited[Depth].emplace(Num);
        
        int MaxNum = -1;
        for(int i = 0; i < M - 1; ++i)
        {
            for(int j = i + 1; j < M; ++j)
            {
                string TmpNum = to_string(Num);
                if(i == 0 && TmpNum[j] == '0')
                {
                    continue;
                }
                swap(TmpNum[i], TmpNum[j]);
                
                MaxNum = max(MaxNum, DFS(stoi(TmpNum), Depth + 1));
            }
        }
        
        return MaxNum;
    }
}

int main()
{
    scanf(" %d %d", &N, &K);
    M = floor(log10(N)+1);
    
    printf("%d", DFS());
    
    return 0;
}