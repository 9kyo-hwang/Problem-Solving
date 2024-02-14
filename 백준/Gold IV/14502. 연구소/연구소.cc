#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum
{
	EMPTY = 0,
	WALL = 1,
	VIRUS = 2
};

int N, M;
vector<vector<int>> lab;
vector<pair<int, int>> empties, viruses;
queue<pair<int, int>> q;

constexpr int OFFSET[][2] =
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int BFS()
{
	for (const auto [x, y] : viruses)
		q.emplace(x, y);

	while(!q.empty())
	{
		const auto [x, y] = q.front(); q.pop();

		for(auto &dir : OFFSET)
		{
			int nx = x + dir[0]; int ny = y + dir[1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || lab[nx][ny] != EMPTY)
				continue;

			lab[nx][ny] = VIRUS;
			q.emplace(nx, ny);
		}
	}

	int numEmpty = 0;
	for(const auto [x, y] : empties)
	{
		if (lab[x][y] == EMPTY) numEmpty++;
		else if (lab[x][y] == VIRUS) lab[x][y] = EMPTY;
	}

	return numEmpty;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	lab = vector(N, vector(M, 0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == VIRUS) viruses.emplace_back(i, j);
			else if (lab[i][j] == EMPTY) empties.emplace_back(i, j);
		}
	}

	int numMax = 0;
	// 벽 3개 설치
	for(int i = 0; i < empties.size() - 2; i++)
	{
		const auto [ix, iy] = empties[i];
		lab[ix][iy] = WALL;

		for(int j = i + 1; j < empties.size() - 1; j++)
		{
			const auto [jx, jy] = empties[j];
			lab[jx][jy] = WALL;

			for(int k = j + 1; k < empties.size(); k++)
			{
				/*
				 * i, j, k번째 빈 칸에 벽을 설치해본 뒤
				 * 안전 구역 크기를 계산해서 그 중 최대값을 찾아보자.
				 */

				const auto [kx, ky] = empties[k];
				lab[kx][ky] = WALL;

				numMax = max(numMax, BFS());

				lab[kx][ky] = EMPTY;
			}
			lab[jx][jy] = EMPTY;
		}
		lab[ix][iy] = EMPTY;
	}

	cout << numMax;

	return 0;
}