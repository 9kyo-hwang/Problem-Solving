#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 1e9

using namespace std;

vector<int> dp;
int solution(int x) {
    if(x <= 1)
        return 0;
    else if(dp[x] > 0)
        return dp[x];
    else
        return dp[x] = min({solution(x / 3) + x % 3 + 1, solution(x / 2) + x % 2 + 1});
}

int main() {
    FASTIO
        
    int X; cin >> X;
    dp = vector<int>(X + 1, 0);
    cout << solution(X);
    
    return 0;
}