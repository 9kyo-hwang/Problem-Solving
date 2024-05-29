#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    using FEdge = tuple<int64_t, int64_t, int64_t>;
    constexpr int64_t INF = LLONG_MAX;

    int64_t N, M, S, E;
    cin >> N >> M >> S >> E;
    S *= 2, E *= 2;
    
    vector<vector<FEdge>> Graph(N + 1);
    while(M--)
    {
        int64_t A, B, L, t1, t2;
        cin >> A >> B >> L >> t1 >> t2;
        
        Graph[A].emplace_back(B, L * 2, t1);
        Graph[B].emplace_back(A, L * 2, t2);
    }
    
    using FNode = pair<int64_t, int64_t>;
    
    priority_queue<FNode, vector<FNode>, greater<>> PQ;
    vector<int64_t> Times(N + 1, INF);
    
    PQ.emplace(0, 1);
    Times[1] = 0;
    
    while(!PQ.empty())
    {
        const auto [tu, u] = PQ.top();
        PQ.pop();
        
        if(Times[u] < tu)
        {
            continue;
        }
        
        for(const auto& [v, dv, t] : Graph[u])
        {
            int64_t Time = dv;
            if(t == 1 && tu < E && S < tu + Time)
            {
                int64_t TrafficStart = tu > S ? tu : S;
                if(2 * (tu + dv - TrafficStart) < E - TrafficStart)
                {
                    Time += (tu + dv - TrafficStart);
                }
                else
                {
                    Time += (E - TrafficStart) / 2;
                }
            }
            
            if(tu + Time < Times[v])
            {
                Times[v] = tu + Time;
                PQ.emplace(Times[v], v);
            }
        }
    }
    
    int64_t MaxTime = 0;
    for(int64_t Node = 1; Node <= N; ++Node)
    {
        MaxTime = max(MaxTime, Times[Node]);
    }
    
    cout << MaxTime / 2;
    if(MaxTime & 1) 
    {
        cout << ".5";
    }

    return 0;
}