#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int V, E; // num of vertices, num of edges
	cin >> V >> E;
	vector<pair<int, int>> graph[20001];

	int K; // start point
	cin >> K;

	while(E--)
	{
		int u, v, w; // start point, end point, weight
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}

	int dist[20001]; fill_n(dist, 20001, INT32_MAX);
	priority_queue<pair<int, int>> pq;

	dist[K] = 0;
	pq.emplace(0, K); // weight, node

	while(!pq.empty())
	{
		auto [weight, start] = pq.top();
		weight *= -1;
		pq.pop();

		if (dist[start] < weight) // already calculated
			continue;

		for(auto [end, distance] : graph[start])
		{
			if(const int w = distance + weight; w < dist[end])
			{
				dist[end] = w;
				pq.emplace(-w, end);
			}
		}
	}

	for(int i = 1; i <= V; i++)
	{
		if (dist[i] == INT32_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}