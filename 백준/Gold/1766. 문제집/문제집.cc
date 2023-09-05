#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M; cin >> N >> M;
	
	vector<vector<int>> graph(N + 1);
	vector<int> in_degrees(N + 1, 0);
	while (M--)
	{
		int A, B; cin >> A >> B;
		graph[A].emplace_back(B);
		in_degrees[B] += 1;
	}

	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (in_degrees[i] == 0)
			pq.emplace(i);
	}

	vector<int> answer;
	while (N--)
	{
		if (pq.empty())
			break;

		int now = pq.top();
		pq.pop();
		answer.emplace_back(now);

		for (const int i : graph[now])
		{
			in_degrees[i] -= 1;
			if (in_degrees[i] == 0)
				pq.emplace(i);
		}
	}

	for (const int i : answer)
		cout << i << " ";

	return 0;
}