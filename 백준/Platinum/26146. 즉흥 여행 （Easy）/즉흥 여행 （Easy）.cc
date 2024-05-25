#include <iostream>
#include <vector>

using namespace std;

int N, M;

void DFSHelper(const vector<vector<int>>& Graph, vector<bool>& Visited, int SrcNode = 1)
{
    Visited[SrcNode] = true;
    for(const auto& DstNode : Graph[SrcNode])
    {
        if(!Visited[DstNode])
        {
            DFSHelper(Graph, Visited, DstNode);
        }
    }
}

bool DFS(vector<vector<int>>& Graph)
{
    vector<bool> Visited(N + 1, false);
    DFSHelper(Graph, Visited);
    
    for(int Node = 1; Node <= N; ++Node)
    {
        if(!Visited[Node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M;
    
    vector<vector<int>> G(N + 1);
    vector<vector<int>> GC(N + 1);
    
    while(M--)
    {
        int v, w; cin >> v >> w;
        G[v].emplace_back(w);
        GC[w].emplace_back(v);
    }
    
    cout << (DFS(G) && DFS(GC) ? "Yes" : "No");

    return 0;
}