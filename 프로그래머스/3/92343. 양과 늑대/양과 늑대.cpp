#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> Info, vector<vector<int>> Edges)
{
    const int N = Info.size();
    
    vector<bool> Visited(1 << N, false);
    vector<vector<int>> Graph(N);
    
    for(const auto& Edge : Edges)
    {
        Graph[Edge[0]].emplace_back(Edge[1]);
    }
    
    int Answer = 0;
    function<void(int)> DFS = [&](int Mask)
    {
        if(Visited[Mask]) return;
        
        Visited[Mask] = true;
        int Sheep = 0, Wolf = 0;
        for(int Node = 0; Node < N; ++Node)
        {
            if(Mask & (1 << Node))
            {
                Sheep += (Info[Node] == 0);
                Wolf += (Info[Node] == 1);
            }
        }
        
        if(Sheep <= Wolf) return;
        
        Answer = max(Answer, Sheep);
        for(int Parent = 0; Parent < N; ++Parent)
        {
            if(!(Mask & (1 << Parent))) continue;
            
            for(int Child : Graph[Parent])
            {
                DFS(Mask | (1 << Child));
            }
        }
    }; DFS(1);
    
    return Answer;
}