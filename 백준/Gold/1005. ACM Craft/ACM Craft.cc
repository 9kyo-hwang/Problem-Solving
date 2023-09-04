#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		int N, K; cin >> N >> K;

		vector<int> build_times(N + 1, 0);
		for (int i = 1; i <= N; i++) cin >> build_times[i];

		vector<vector<int>> graph(N + 1);
		vector<int> in_degress(N + 1, 0);
		while (K--)
		{
			int X, Y; cin >> X >> Y;
			graph[X].emplace_back(Y);
			in_degress[Y] += 1;
		}

		int W; cin >> W;

		queue<int> q;
		vector<int> dp(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			if (in_degress[i] == 0)
			{
				q.emplace(i);
				dp[i] = build_times[i];
			}
		}

		while (N--)
		{
			if (q.empty()) break;
			
			int node = q.front();
			q.pop();

			for (const int adj_node : graph[node])
			{
				in_degress[adj_node] -= 1;
				dp[adj_node] = max(dp[adj_node], dp[node] + build_times[adj_node]);
				if (in_degress[adj_node] == 0)
				{
					q.emplace(adj_node);
				}
			}
		}

		cout << dp[W] << "\n";
	}

	return 0;
}