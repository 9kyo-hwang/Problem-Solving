#include <iostream>
#include <vector>

using namespace std;

int N, M; 
vector<vector<int>> Graph;
vector<bool> Visited;

bool DFS(int Src, int Depth = 0)
{
    if(Depth == 4)
    {
        return true;
    }
    
    Visited[Src] = true;
    for(int Dst : Graph[Src])
    {
        if(Visited[Dst])
        {
            continue; 
        }
        
        if(DFS(Dst, Depth + 1))
        {
            return true;
        }
    }
    Visited[Src] = false;
    
    return false;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    Graph.assign(N, {});
    Visited.assign(N, false);
    
    while(M--)
    {
        int A, B; cin >> A >> B;
        Graph[A].emplace_back(B);
        Graph[B].emplace_back(A);
    }
    
    bool Result = false;
    for(int Node = 0; Node < N; ++Node)
    {
        if(Visited[Node])
        {
            continue;
        }
        
        Result = DFS(Node);
        if(Result)
        {
            break;
        }
    }
    
    cout << Result;
    
    return 0;
}