#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    int MaxHeight = 0;
    vector<int> TreeHeights(N);
    for(int& Height : TreeHeights) 
    {
        cin >> Height;
        if(Height > MaxHeight)
        {
            MaxHeight = Height;    
        } 
    }
    
    auto Check = [&](int Mid)
    {
        long long HeightSum = 0;
        for(int& Height : TreeHeights)
        {
            if(Height > Mid)
            {
                HeightSum += Height - Mid;
            }
        }
        return HeightSum;
    };

    int Low = 1, High = MaxHeight;
    int Answer = 0;
    while(Low <= High) 
    {
        int Mid = (Low + High) / 2;

        if(Check(Mid) < M)
        {
            High = Mid - 1;
        }
        else
        {
            Low = Mid + 1;
        }
    }

    cout << High;

    return 0;
}