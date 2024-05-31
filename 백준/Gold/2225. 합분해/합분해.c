#include <stdio.h>
#define MOD 1000000000

int main() {
    int N, K; scanf(" %d %d", &N, &K);
    int dp[201] = {1, };
    
    for(int select = 1; select <= K; ++select) {
        for(int number = 1; number <= N; ++number) {
            dp[number] += dp[number - 1];
            dp[number] %= MOD;
        }
    }
    
    printf("%d", dp[N]);

    return 0;
}