#include <string>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

int solution(vector<int> Info, vector<vector<int>> Edges)
{
    const size_t N = Info.size();
    
    vector<vector<int>> Graph(N);
    for(const auto& Edge : Edges)
    {
        Graph[Edge[0]].emplace_back(Edge[1]);
        //Graph[Edge[1]].emplace_back(Edge[0]);
    }
    vector<bool> Visited(1 << N, false);  // 2^N 개수만큼
    
    vector<int> Parents(N);
    function<void(int, int)> FindParent = [&](int Begin, int End)
    {
        for(int Dst: Graph[Begin])
        {
            if(Dst == End) continue;
            
            Parents[Dst] = Begin;
            FindParent(Dst, Begin);
        }
    }; FindParent(0, -1);
    
    int Answer = 0;
    function<void(int, int, int)> DFS = [&](int Mask, int Sheep, int Wolf)
    {
        Visited[Mask] = true;
        Answer = max(Answer, Sheep);
        
        for(int Src = 0; Src < N; ++Src)
        {
            if(~Mask >> Src & 1) continue;
            
            for(int Dst : Graph[Src])
            {
                if(Dst == Parents[Src] || Mask >> Dst & 1) continue;
                
                int NextMask = Mask | (1 << Dst);
                if(Visited[NextMask]) continue;
                
                if(Sheep + (Info[Dst] == 0) <= Wolf + (Info[Dst] == 1)) continue;
                
                DFS(NextMask, Sheep + (Info[Dst] == 0), Wolf + (Info[Dst] == 1));
            }
        }
    }; DFS(1, 1, 0);
    
    return Answer;
}