#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k; // num of coin, target price
	cin >> n >> k;

	vector<int> coin(n);
	for (auto& i : coin) cin >> i;

	// 마지막으로 X원을 사용해 K원을 만들 때 필요한 동전 최소 개수
	// : 기존에 구해둔 (K - X)원을 만드는 데 필요한 동전 최소 개수
	// + X원 1개 사용

	vector<int> dp(k + 1, 10001);
	dp[0] = 0; // 0원: 아무것도 안 갖고 있는 경우
	for (int i = 0; i < n; i++) dp[coin[i]] = 1; // 동전이 있다면 그 동전 하나로 값을 만들 수 있음(최소).

	// dp[3]: 3원을 만드는데 필요한 동전 최소 개수
	for(const auto price : coin) // 동전 사용
	{
		for(int goal = 1; goal <= k; goal++) // 목표 금액(1원 ~ k원)
		{
			if (goal < price) continue; // 현재 동전으로 만들 수 없는 금액

			dp[goal] = min(dp[goal], dp[goal - price] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];

	return 0;
}