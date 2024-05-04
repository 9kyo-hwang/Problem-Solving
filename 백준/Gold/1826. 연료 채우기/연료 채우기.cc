#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<pair<int, int>> Info(N);
    for(auto& [a, b] : Info)
    {
        cin >> a >> b;
    }
    int L, P; cin >> L >> P;
    Info.emplace_back(L, 0);
    
    sort(Info.begin(), Info.end());
    
    int Answer = 0;
    priority_queue<int> PQ;
    for(const auto& [a, b] : Info)
    {
        if(P < a)
        {
            while(!PQ.empty() && P < a)
            {
                P += PQ.top();
                PQ.pop();
                Answer += 1;
            }
            
            if(P < a)
            {
                break;
            }
        }
        
        PQ.emplace(b);
    }
    
    if(P >= L)
    {
        cout << Answer;
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}