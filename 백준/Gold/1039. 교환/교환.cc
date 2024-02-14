#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string N; int K;
vector<vector<int>> DP;

int DFS(string Num, int Depth)
{
    if(Depth == K)
    {
        return stoi(Num);
    }
    else if(DP[Depth][stoi(Num)] != 0)
    {
        return DP[Depth][stoi(Num)];
    }
    else
    {
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
        return DP[Depth][stoi(Num)] = MaxNum;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;
    DP.assign(K + 1, vector<int>(1000001, 0));
    
    cout << DFS(N, 0);
    
    return 0;
}