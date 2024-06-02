#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> Info, vector<vector<int>> Edges) 
{
    enum EInfo
    {
        Sheep = 0,
        Wolf = 1,
        Checked = 2
    };
    
    const int N = Info.size();

    vector<vector<int>> Tree(N);
    for(const auto& Edge : Edges)
    {
        Tree[Edge[0]].emplace_back(Edge[1]);
        Tree[Edge[1]].emplace_back(Edge[0]);
    }
    
    vector<vector<vector<bool>>> Visited(N, vector(N + 1, vector(N + 1, false)));
    Visited[0][1][0] = true;
    Info[0] = EInfo::Checked;
    
    int Answer = 0;
    function<void(int, int, int)> Backtracking = [&](int Src, int Sheep, int Wolf)
    {
        Answer = max(Answer, Sheep);
        for(int Dst : Tree[Src])
        {
            if(Info[Dst] == EInfo::Sheep && !Visited[Dst][Sheep + 1][Wolf])
            {
                Visited[Dst][Sheep + 1][Wolf] = true;
                Info[Dst] = EInfo::Checked;
                Backtracking(Dst, Sheep + 1, Wolf);
                Info[Dst] = EInfo::Sheep;
                Visited[Dst][Sheep + 1][Wolf] = false;
            }
            else if(Info[Dst] == EInfo::Wolf && Sheep > Wolf + 1 && !Visited[Dst][Sheep][Wolf + 1])
            {
                Visited[Dst][Sheep][Wolf + 1] = true;
                Info[Dst] = EInfo::Checked;
                Backtracking(Dst, Sheep, Wolf + 1);
                Info[Dst] = EInfo::Wolf;
                Visited[Dst][Sheep][Wolf + 1] = false;
            }
            else if(Info[Dst] == EInfo::Checked && !Visited[Dst][Sheep][Wolf])
            {
                Visited[Dst][Sheep][Wolf] = true;
                Backtracking(Dst, Sheep, Wolf);
                Visited[Dst][Sheep][Wolf] = false;
            }
        }
    }; Backtracking(0, 1, 0);
    
    return Answer;
}