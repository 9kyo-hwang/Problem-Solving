#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;

	vector<int> graph[10001];
	while(M--)
	{
		int A, B; cin >> A >> B;

		graph[A].emplace_back(B);
		graph[B].emplace_back(A);
	}

	for (auto& v : graph) sort(v.begin(), v.end());

	int S, E; cin >> S >> E;

	bool visited[10001] = {};
	int parent[10001] = { 0, };

	queue<pair<int, int>> q;
	q.emplace(S, 0);
	visited[S] = true;

	int dist = 0;
	while(!q.empty())
	{
		const auto [s, d] = q.front(); q.pop();

		if (s == E)
		{
			dist += d;
			break;
		}

		for (const auto e : graph[s])
		{
			if(!visited[e])
			{
				visited[e] = true;
				parent[e] = s;
				q.emplace(e, d + 1);
			}
		}
	}

	memset(visited, false, 10001);
	int p = parent[E];
	while(p != S)
	{
		visited[p] = true;
		p = parent[p];
	}

	q = queue<pair<int, int>>();
	q.emplace(E, 0);
	visited[E] = true;

	while(!q.empty())
	{
		const auto [s, d] = q.front(); q.pop();

		if(s == S)
		{
			dist += d;
			break;
		}

		for (const auto e : graph[s])
		{
			if (!visited[e])
			{
				visited[e] = true;
				q.emplace(e, d + 1);
			}
		}
	}

	cout << dist;
	return 0;
}