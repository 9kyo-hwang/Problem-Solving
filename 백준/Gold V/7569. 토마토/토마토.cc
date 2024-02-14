#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using DataPtr = struct Data*;

struct Data
{
	int Z, X, Y, Day;

	Data(const int z, const int x, const int y, const int d)
	: Z(z), X(x), Y(y), Day(d)
	{
		
	}
};

int M, N, H, numUnripe = 0;
vector<vector<vector<int>>> farm, visited;
queue<DataPtr> q;

enum
{
	EMPTY = -1,
	UNRIPE = 0,
	RIPE = 1
};

int offset[][3] =
{
	{0, -1, 0}, // N
	{0, 0, 1}, // E
	{0, 1, 0}, // S
	{0, 0, -1}, // W
	{-1, 0, 0}, // Up
	{1, 0, 0} // Down
};

bool IsOut(const int z, const int x, const int y)
{
	return z < 0 || z >= H || x < 0 || x >= N || y < 0 || y >= M;
}

int GetDay()
{
	int totalDays = 0;
	while (!q.empty())
	{
		auto front = q.front();
		int z = front->Z, x = front->X, y = front->Y, day = front->Day;
		q.pop();
		totalDays = day;

		for (const auto& dir : offset)
		{
			int nz = z + dir[0], nx = x + dir[1], ny = y + dir[2];

			if (IsOut(nz, nx, ny) || visited[nz][nx][ny] == 1) continue;

			if (farm[nz][nx][ny] == EMPTY) continue;

			visited[nz][nx][ny] = 1;
			farm[nz][nx][ny] = RIPE;
			q.push(new Data(nz, nx, ny, day + 1));
			numUnripe--;
		}
	}

	return totalDays;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> M >> N >> H; // col, row, height
	farm = vector(H, vector(N, vector<int>(M)));
	visited = vector(H, vector(N, vector(M, 0)));

	for(int z = 0; z < H; z++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				cin >> farm[z][x][y];
				if (farm[z][x][y] == RIPE)
				{
					q.push(new Data(z, x, y, 0));
					visited[z][x][y] = 1;
				}
				else if (farm[z][x][y] == UNRIPE) numUnripe++;
			}
		}
	}

	int days = GetDay();
	if (numUnripe != 0) days = -1;
	cout << days;

	return 0;
}