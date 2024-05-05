#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    vector<int> T(N, 0);
    for(int& Ti : T)
    {
        cin >> Ti;
    }
    
    sort(T.begin(), T.end());
    int i = 0, j = N - 1, k = 0;
    int64_t Answer = 0;
    while(k < K)
    {
        if(k == 0)
        {
            Answer = T[j--];
            ++k;
            continue;
        }
        
        if(k & 1)
        {
            ++i;
        }
        else
        {
            Answer += T[j--] - T[i - 1];
        }
        ++k;
    }
    cout << Answer;
    
    return 0;
}