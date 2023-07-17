#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vertices(N + 1);
	while(M--)
	{
		int a, b;
		cin >> a >> b;

		vertices[a].emplace_back(b);
		vertices[b].emplace_back(a);
	}

	vector<int> visited(N + 1, 0);

	int count = 0;
	for(int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;

		queue<int> q;
		q.emplace(i);
		visited[i] = 1;

		while(!q.empty())
		{
			const int num = q.front();
			q.pop();

			for(auto adj : vertices[num])
			{
				if (visited[adj] == 1)
					continue;

				visited[adj] = 1;
				q.emplace(adj);
			}
		}
		count++;
	}

	cout << count;

	return 0;
}