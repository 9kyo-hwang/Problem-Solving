#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;

int N;
int numMinus = 0, numZero = 0, numOne = 0;

bool IsOut(int x, int y)
{
	return x < 0 || x >= N || y < 0 || y >= N;
}

bool IsSame(int size, int x, int y)
{
	int color = paper[x][y];
	for(int i = x; i < x + size; i++)
	{
		for(int j = y; j < y + size; j++)
		{
			if (paper[i][j] != color)
				return false;
		}
	}
	return true;
}

void CheckPaper(int size, int x, int y)
{
	if (IsOut(x, y)) return;
	if (IsSame(size, x, y))
	{
		switch (paper[x][y])
		{
		case -1: numMinus++; break;
		case 0: numZero++; break;
		case 1: numOne++; break;
		default: break;
		}
		return;
	}

	size /= 3;
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 2; j++)
			CheckPaper(size, x + i * size, y + j * size);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	paper = vector<vector<int>>(N, vector<int>(N));
	for (auto& v : paper) for (auto& i : v) cin >> i;

	CheckPaper(N, 0, 0);
	cout << numMinus << "\n" << numZero << "\n" << numOne;

	return 0;
}