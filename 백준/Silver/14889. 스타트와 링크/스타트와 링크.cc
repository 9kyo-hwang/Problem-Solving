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
    
    vector<bool> Selected(N / 2, false);
    Selected.insert(Selected.end(), N / 2, true);
    
    int Answer = 40001;
    do
    {
        int Start = 0, Link = 0;
        for(int i = 0; i < N - 1; ++i)
        {
            for(int j = i + 1; j < N; ++j)
            {
                if(Selected[i] && Selected[j])
                {
                    Start += Table[i][j] + Table[j][i];
                }
                if(!Selected[i] && !Selected[j])
                {
                    Link += Table[i][j] + Table[j][i];
                }
            }
        }
        Answer = min(Answer, abs(Start - Link));
    } while(next_permutation(Selected.begin(), Selected.end()));
    
    cout << Answer;
    
    return 0;
}