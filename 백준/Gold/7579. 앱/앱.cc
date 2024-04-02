#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; 
    cin >> N >> M;
    
    vector<pair<int, int>> A(N);
    for(auto& [MemoryUsage, RefreshCost] : A)
    {
        cin >> MemoryUsage;
    }
    
    int TotalRefreshCost = 0;
    for(auto& [MemoryUsage, RefreshCost] : A)
    {
        cin >> RefreshCost;
        TotalRefreshCost += RefreshCost;
    }
    
    vector<int> MaxMemoryEachCost(TotalRefreshCost + 1, 0);
    for(const auto& [MemoryUsage, RefreshCost] : A)
    {
        for(int Cost = TotalRefreshCost; Cost >= RefreshCost; --Cost)
        {
            MaxMemoryEachCost[Cost] = max
            (
                MaxMemoryEachCost[Cost], 
                MaxMemoryEachCost[Cost - RefreshCost] + MemoryUsage
            );
        }
    }
    
    int Answer = 0;
    for(int Cost = 0; Cost <= TotalRefreshCost; ++Cost)
    {
        if(MaxMemoryEachCost[Cost] >= M)
        {
            Answer = Cost;
            break;
        }
    }
    cout << Answer;

    return 0;
}