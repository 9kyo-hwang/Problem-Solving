#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int64_t N; cin >> N;
    vector<int> Dice(6, 0);
    for(int& Pip : Dice)
    {
        cin >> Pip;
    }
    
    int SumPip = reduce(Dice.begin(), Dice.end(), 0);
    int MaxPip = *max_element(Dice.begin(), Dice.end());

    if(N == 1)
    {
        cout << SumPip - MaxPip;
        return 0;
    }
    
    int Min1D = *min_element(Dice.begin(), Dice.end()), Min2D = 101, Min3D = 151;
    for(int i = 0; i < 6; ++i)
    {
        for(int j = i + 1; j < 6; ++j)
        {
            if(i + j == 5)  // 마주보는 면은 2면은 보이는 주사위가 될 수 없음
            {
                continue;
            }
            
            Min2D = min(Min2D, Dice[i] + Dice[j]);
            
            for(int k = j + 1; k < 6; ++k)
            {
                if(i + k == 5 || j + k == 5)  // 마주보는 면은 2면은 보이는 주사위가 될 수 없음
                {
                    continue;
                }
                
                Min3D = min(Min3D, Dice[i] + Dice[j] + Dice[k]);
            }
        }
    }
    
    int64_t Answer = 0;
    Answer += 4 * Min3D;
    Answer += (8 * N - 12) * Min2D;
    Answer += (5 * N * N - 16 * N + 12) * Min1D;
    cout << Answer;
    
    return 0;
}