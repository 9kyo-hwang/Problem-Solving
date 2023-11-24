//#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAX = 50;
constexpr int INF = 987654321;

enum
{
	EMPTY = 0,
	HOUSE = 1,
	CHICKEN = 2
};

int N, M;
int map[MAX][MAX];
int house[MAX * 2][2]; int numHouse = 0;
int chicken[13][2]; int numChicken = 0;
bool removed[13];

/**
 * m: 없앨 치킨집 개수
 */
int GetDist(const int level, const int m)
{
	if(m == 0)
	{
		int dist = 0;
		for(int i = 0; i < numHouse; i++)
		{
			int minDist = INF;

			const int hx = house[i][0];
			const int hy = house[i][1];

			for(int j = 0; j < numChicken; j++)
			{
				if (removed[j]) continue;

				const int cx = chicken[j][0];
				const int cy = chicken[j][1];
				minDist = min(minDist, abs(hx - cx) + abs(hy - cy));
			}

			dist += minDist;
		}

		return dist;
	}

	int minDist = INF;
	for(int l = level; l < numChicken; l++)
	{
		if (removed[l]) continue;

		removed[l] = true;
		minDist = min(minDist, GetDist(l, m - 1));
		removed[l] = false;
	}

	return minDist;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr); cout.tie(nullptr);

	scanf("%d %d", &N, &M);
	//cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			//cin >> map[i][j];
			if (map[i][j] == HOUSE)
			{
				house[numHouse][0] = i;
				house[numHouse][1] = j;
				numHouse++;
			}
			else if (map[i][j] == CHICKEN)
			{
				chicken[numChicken][0] = i;
				chicken[numChicken][1] = j;
				numChicken++;
			}
		}
	}

	printf("%d", GetDist(0, numChicken - M));
	//cout << GetDist(0, numChicken - M);
	return 0;
}