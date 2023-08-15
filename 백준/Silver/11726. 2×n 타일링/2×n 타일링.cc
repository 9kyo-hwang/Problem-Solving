#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	/**
	 * 2 x 1: 1가지
	 * 2 x 2 = (2 x 1) x 2 or (1 x 2) x 2: 2가지
	 * 2 x 3 = (2 x 1) x 2 + 2 x 1 or (1 x 2) x 2 + 2 x 1 or (1 x 2) + (2 x 1) x 2: 3가지
	 * ...
	 * 2 x N = (2 x (N - 2)) + (2 x (N - 1))
	 */

	int dp[1001]; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	cout << dp[n];

	return 0;
}