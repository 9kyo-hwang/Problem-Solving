#include <cstdio>
#include <vector>

using namespace std;

int main()
{
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
            for(const auto& [DstNode, Time] : Graph[SrcNode])
            {
                if(Distances[SrcNode] + Time < Distances[DstNode])
                {
                    Distances[DstNode] = Distances[SrcNode] + Time;
                    bHasBeenUpdated = true;
                }
            }
        }
        return bHasBeenUpdated;
    };
    
    auto BellmanFord = [&]()
    {
        for(int Repeat = 0; Repeat < N; ++Repeat)
        {
            if(UpdateDistances() && Repeat == N - 1)
            {
                return true;
            }
        }
        return false;
    };
    
    scanf(" %d", &TC);
    while(TC--)
    {
        scanf(" %d %d %d", &N, &M, &W);
        Graph.assign(N + 1, {});
        Distances.assign(N + 1, INF);
        
        for(int i = 0; i < M; ++i)
        {
            
            scanf(" %d %d %d", &S, &E, &T);
            Graph[S].emplace_back(E, T);
            Graph[E].emplace_back(S, T);
        }
        
        for(int i = 0; i < W; ++i)
        {
            scanf(" %d %d %d", &S, &E, &T);
            Graph[S].emplace_back(E, -T);
        }
        
        if(BellmanFord())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}