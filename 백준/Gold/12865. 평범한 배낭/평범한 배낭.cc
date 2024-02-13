#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K; 
    cin >> N >> K;
    
    vector<pair<int, int>> Objects(N);
    for(auto& [Weight, Value] : Objects)
    {
        cin >> Weight >> Value;
    }
    sort(Objects.begin(), Objects.end());
    
    vector<int> MaxValues(K + 1, 0);
    for(const auto&[Weight, Value] : Objects)
    {
        for(int MaxLoad = K; MaxLoad >= 0; --MaxLoad)
        {
            if(Weight > MaxLoad)
            {
                break;
            }
            
            MaxValues[MaxLoad] = max(MaxValues[MaxLoad], MaxValues[MaxLoad - Weight] + Value);
        }
    }
    
    cout << MaxValues[K];

    return 0;
}