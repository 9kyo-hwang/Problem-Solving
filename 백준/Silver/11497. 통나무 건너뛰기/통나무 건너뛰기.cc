#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> Heights(N, 0);
        for(int& Height : Heights)
        {
            cin >> Height;
        }
        
        sort(Heights.begin(), Heights.end());
        vector<int> Best(N, 0);
        
        int i = 0, j = N - 1, Cnt = 0;
        while(Cnt < N)
        {
            if(Cnt & 1)
            {
                Best[j--] = Heights[Cnt++];
            }
            else
            {
                Best[i++] = Heights[Cnt++];
            }
        }
        
        int Answer = 0;
        for(int k = 1; k < N; ++k)
        {
            Answer = max(Answer, abs(Best[k] - Best[k - 1]));
        }
        cout << Answer << "\n";
    }
    
    return 0;
}