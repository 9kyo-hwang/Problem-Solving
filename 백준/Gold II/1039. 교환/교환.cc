#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string N; int K;
vector<vector<bool>> Visited;

int DFS(string Num, int Depth)
{
    if(Visited[Depth][stoi(Num)])
    {
        return -1;
    }
    else if(Depth == K)
    {
        return stoi(Num);
    }
    else
    {
        Visited[Depth][stoi(Num)] = true;
        
        int MaxNum = -1;
        for(int i = 0; i < N.size() - 1; ++i)
        {
            for(int j = i + 1; j < N.size(); ++j)
            {
                if(i == 0 && Num[j] == '0')
                {
                    continue;
                }
                
                string TmpNum = Num;
                swap(TmpNum[i], TmpNum[j]);
                
                MaxNum = max(MaxNum, DFS(TmpNum, Depth + 1));
            }
        }
        
        return MaxNum;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;
    Visited.assign(K + 1, vector<bool>(1000001, false));
    
    cout << DFS(N, 0);
    
    return 0;
}