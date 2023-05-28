#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int OFFSET[][2] =
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int N, L, R;
vector<vector<int>> ground, visited;

bool BFS(int i, int j)
{
	visited[i][j] = 1;
	queue<pair<int, int>> q;
	q.emplace(i, j);

	vector<pair<int, int>> adj;
	int sum = 0; int count = 0;
	while (!q.empty())
	{
		const auto [x, y] = q.front(); q.pop();
		sum += ground[x][y];
		count++;
		adj.emplace_back(x, y);

		for (auto& dir : OFFSET)
		{
			int nx = x + dir[0]; int ny = y + dir[1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] == 1
				|| abs(ground[x][y] - ground[nx][ny]) < L
				|| abs(ground[x][y] - ground[nx][ny]) > R)
				continue;

			visited[nx][ny] = 1;
			q.emplace(nx, ny);
		}
	}

	if(count > 1)
	{
		for(const auto [x, y] : adj)
			ground[x][y] = sum / count;

		return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> L >> R;

	ground = vector(N, vector(N, 0));
	for (auto& v : ground) for (auto& i : v) cin >> i;

	int day = 0;
	while(true)
	{
		int move = 0;
		visited = vector(N, vector(N, 0));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0)
				{
					if (BFS(i, j))
						move++;
				}
			}
		}

		if (move == 0) break;
		day++;
	}

	cout << day;

	return 0;
}