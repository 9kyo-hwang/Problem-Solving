#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr int LOG_MAX_N = ceil(log2(500000));
    
    int m; cin >> m;
    
    // SparseTable[n][x]: 정점 x에서 n번 진행했을 때 도달하는 지점
    vector<vector<int>> SparseTable(LOG_MAX_N, vector(m + 1, 0));
    for(int x = 1; x <= m; ++x)
    {
        // log2(1) == 0. 즉 1번 이동했을 때
        cin >> SparseTable[0][x];
    }
    
    for(int n = 1; n < LOG_MAX_N; ++n)
    {
        for(int x = 1; x <= m; ++x)
        {
            SparseTable[n][x] = SparseTable[n - 1][SparseTable[n - 1][x]];
        }
    }
    
    int q; cin >> q;
    while(q--)
    {
        // N == 7 == 0111: 1, 2, 4번 이동 확인
        int n, x; cin >> n >> x;
        for(int i = 0; i < LOG_MAX_N; ++i)
        {
            if(n & (1 << i))
            {
                x = SparseTable[i][x];
            }
        }
        cout << x << "\n";
    }
    
    return 0;
}