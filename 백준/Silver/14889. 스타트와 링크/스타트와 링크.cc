#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<vector<int>> Table(N, vector(N, 0));
    
    for(auto& Row : Table)
    {
        for(auto& Col : Row)
        {
            cin >> Col;
        }
    }
    
    int Answer = 40001;
    vector<int> Start, Link;
    for(int Comb = N / 2; Comb < (1 << N); ++Comb)
    {
        if(__builtin_popcount(Comb) != (N >> 1)) continue;
        
        Start.clear();
        Link.clear();
        
        for(int i = 0; i < N; ++i)
        {
            Comb & (1 << i) ? Start.emplace_back(i) : Link.emplace_back(i);
        }
        
        int StartScore = 0, LinkScore = 0;
        for(int i = 0; i < N / 2; ++i)
        {
            for(int j = 0; j < N / 2; ++j)
            {
                if(i == j) continue;
                StartScore += Table[Start[i]][Start[j]];
                LinkScore += Table[Link[i]][Link[j]];
            }
        }
        
        Answer = min(Answer, abs(StartScore - LinkScore));
    }
    
    cout << Answer;
}