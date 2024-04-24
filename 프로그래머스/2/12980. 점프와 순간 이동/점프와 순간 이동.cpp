#include <iostream>
#include <unordered_map>

using namespace std;
constexpr int MAX = 1000000000;

unordered_map<int, int> dp;

int solution(int n) {
    if(n == 0) {
        return 0;
    } else if(n < 0) {
        return MAX;
    } else if(dp.count(n)) {
        return dp[n];
    } else {
        return dp[n] = (n & 1 ? solution(n - 1) + 1 : solution(n / 2));
    }
}