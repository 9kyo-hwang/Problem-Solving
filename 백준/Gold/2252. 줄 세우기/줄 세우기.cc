#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> in_degrees(N + 1, 0);
	int A, B;

	while (M--)
	{
		cin >> A >> B;
		graph[A].emplace_back(B);
		in_degrees[B] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (in_degrees[i] == 0)
		{
			q.emplace(i);
		}
	}

	vector<int> answer;
	while (N--)
	{
		if (q.empty()) break;

		int node = q.front();
		q.pop();
		answer.emplace_back(node);

		for (const int adj_node : graph[node])
		{
			in_degrees[adj_node] -= 1;
			if (in_degrees[adj_node] == 0)
			{
				q.emplace(adj_node);
			}
		}
	}
	
	for (const int node : answer) cout << node << " ";

	return 0;
}