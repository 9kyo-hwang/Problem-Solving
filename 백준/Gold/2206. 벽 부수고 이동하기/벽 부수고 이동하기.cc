#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

enum
{
	PATHWAY = 0,
	WALL = 1,
};

int N, M; // row, col
int map[1000][1000];
bool visited[1000][1000][2];

int offset[][2] =
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

bool IsOut(int x, int y)
{
	return x < 0 || x >= N || y < 0 || y >= M;
}

int NumShortestPath()
{
	// x, y 좌표, 벽 파괴 유무, 이동 거리
	queue<tuple<pair<int, int>, bool, int>> q;
	q.push({ { 0, 0 }, false, 1 });
	visited[0][0][0] = true;

	int count = -1;
	while(!q.empty())
	{
		auto front = q.front();
		int x = get<0>(front).first;
		int y = get<0>(front).second;
		bool flag = get<1>(front);
		int distance = get<2>(front);
		q.pop();

		if(x == N - 1 && y == M - 1)
		{
			count = distance;
			break;
		}

		for(auto &dir : offset)
		{
			int nx = x + dir[0], ny = y + dir[1];
			if (IsOut(nx, ny) || visited[nx][ny][flag]) continue;

			if(!flag && map[nx][ny] == PATHWAY)
			{
				visited[nx][ny][0] = true;
				q.push({ { nx, ny }, false, distance + 1 });
			}
			else if(!flag && map[nx][ny] == WALL)
			{
				visited[nx][ny][1] = true;
				q.push({ { nx, ny }, true, distance + 1 });
			}
			else if(flag && map[nx][ny] == PATHWAY)
			{
				visited[nx][ny][1] = true;
				q.push({ { nx, ny }, true, distance + 1 });
			}
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
			map[i][j] = line[j] - '0';
	}
	
	int result = NumShortestPath();
	cout << result;

	return 0;
}