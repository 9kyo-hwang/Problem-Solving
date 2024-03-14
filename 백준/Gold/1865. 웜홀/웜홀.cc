#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    using FEdge = pair<int, int>;
    constexpr int INF = 1e9;
    
    int TC; 
    int N, M, W, S, E, T;
    vector<vector<FEdge>> Graph;
    vector<int> Distances;
    
    auto UpdateDistances = [&]()
    {
        bool bHasBeenUpdated = false;
        for(int SrcNode = 1; SrcNode <= N; ++SrcNode)
        {
            for(const auto& [DstNode, Cost] : Graph[SrcNode])
            {
                if(Distances[SrcNode] + Cost < Distances[DstNode])
                {
                    Distances[DstNode] = Distances[SrcNode] + Cost;
                    bHasBeenUpdated = true;
                }
            }
        }
        return bHasBeenUpdated;
    };
    
    auto BellmanFord = [&]()
    {
        for(int Repeat = 0; Repeat < N - 1; ++Repeat)
        {
            UpdateDistances();
        }
    };
    
    auto HasNevativeCycle = [&]()
    {
        return UpdateDistances();
    };
    
    cin >> TC;
    while(TC--)
    {
        cin >> N >> M >> W;
        Graph.assign(N + 1, {});
        Distances.assign(N + 1, INF);
        
        for(int i = 0; i < M; ++i)
        {
            cin >> S >> E >> T;
            Graph[S].emplace_back(E, T);
            Graph[E].emplace_back(S, T);
        }
        
        for(int i = 0; i < W; ++i)
        {
            cin >> S >> E >> T;
            Graph[S].emplace_back(E, -T);
        }
        
        BellmanFord();
        if(HasNevativeCycle())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}