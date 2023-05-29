#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		int num; cin >> num;

		vector<int> dp(11, 0);
		dp[1] = 1; dp[2] = 2; dp[3] = 4; // 기본값

		for (int i = 4; i <= num; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		cout << dp[num] << "\n";
	}

	return 0;
}