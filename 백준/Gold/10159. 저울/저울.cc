#include <cstdio>

using namespace std;

constexpr int INF = 987654321;
bool compare[101][101];

int main()
{
	int N, M; scanf("%d %d", &N, &M);

	while(M--)
	{
		int a, b; scanf("%d %d", &a, &b);
		compare[a][b] = true;
	}

	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				// i > k && k > j -> i > j
				if (compare[i][k] && compare[k][j])
					compare[i][j] = true;
			}
		}
	}

	
	for (int i = 1; i <= N; i++)
	{
		int count = 0;
		for (int j = 1; j <= N; j++)
		{
			// i > j인 지도 알 수 없고 j > i인 지도 알 수 없음
			if (i != j && !compare[i][j] && !compare[j][i])
				count++;
		}
		printf("%d\n", count);
	}

	return 0;
}