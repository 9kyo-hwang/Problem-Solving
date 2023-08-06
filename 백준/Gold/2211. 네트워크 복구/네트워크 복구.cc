#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;

// MST로는 풀리지 않음. 기존 네트워크 통신 최소 시간보다 커지는 경우가 생김. SP로 해결

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, M; // num of cities, num of bus
	cin >> N >> M;
	vector<pair<int, int>> graph[1001];

	while (M--)
	{
		int A, B, D; // start point, end point, distance
		cin >> A >> B >> D;
		graph[A].emplace_back(B, D);
		graph[B].emplace_back(A, D);
	}

	vector<int> dist(1001, INF);
	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.emplace(0, 1); // weight, start

	vector<int> parents(1001, -1);
	while (!pq.empty())
	{
		auto [weight, start] = pq.top();
		weight *= -1;
		pq.pop();

		if (dist[start] < weight) // already calculated
			continue;

		for (auto [end, distance] : graph[start])
		{
			if (const int w = distance + weight; w < dist[end])
			{
				parents[end] = start;
				dist[end] = w;
				pq.emplace(-w, end);
			}
		}
	}

	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++)
		cout << parents[i] << " " << i << "\n";

	return 0;
}