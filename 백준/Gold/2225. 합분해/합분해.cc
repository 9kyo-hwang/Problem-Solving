#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9;

int N, K;
vector<vector<int>> DP;

int Backtracking(int RemainNumber = N, int RemainSelect = K)
{
    if(RemainNumber < 0)
    {
        return 0;
    }
    else if(RemainSelect == 0)
    {
        return RemainNumber == 0;
    }
    else if(DP[RemainNumber][RemainSelect] > 0)
    {
        return DP[RemainNumber][RemainSelect];
    }
    else
    {
        for(int SubtractNumber = 0; SubtractNumber <= N; ++SubtractNumber)
        {
            DP[RemainNumber][RemainSelect] += Backtracking(RemainNumber - SubtractNumber, RemainSelect - 1);
            DP[RemainNumber][RemainSelect] %= MOD;
        }
        return DP[RemainNumber][RemainSelect];
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;
    DP.assign(N + 1, vector(K + 1, 0));
    cout << Backtracking() << "\n";

    return 0;
}