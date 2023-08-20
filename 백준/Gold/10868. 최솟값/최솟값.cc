#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using GroupPtr = struct Group*;

struct Group
{
	int Minimum{};
	vector<int> Data;
};

int N, M, G;
vector<GroupPtr> v;

int RangeQuery(int i, int j)
{
	const int iGroup = i / M;
	const int iIndex = i % M;
	const int jGroup = j / M;
	const int jIndex = j % M;

	int minimum = 1'000'000'001;

	if(iGroup == jGroup)
	{
		for(int index = iIndex; index <= jIndex; index++)
		{
			minimum = min(minimum, v[iGroup]->Data[index]);
		}
		return minimum;
	}

	for(int index = iIndex; index < M; index++)
	{
		minimum = min(minimum, v[iGroup]->Data[index]);
	}

	for(int group = iGroup + 1; group < jGroup; group++)
	{
		minimum = min(minimum, v[group]->Minimum);
	}

	for(int index = 0; index <= jIndex; index++)
	{
		minimum = min(minimum, v[jGroup]->Data[index]);
	}

	return minimum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Q;
	cin >> N >> Q;

	M = static_cast<int>(floor(sqrt(N)));
	G = static_cast<int>(ceil(static_cast<double>(N) / M));

	for(int i = 0; i < G; i++)
	{
		int n; cin >> n;

		auto group = new struct Group;
		group->Data.emplace_back(n);
		N--;

		int min = n;
		for(int j = 1; j < M && N > 0; j++)
		{
			cin >> n;
			group->Data.emplace_back(n);
			N--;

			if (n < min) min = n;
		}

		group->Minimum = min;
		v.emplace_back(group);
	}

	while(Q--)
	{
		int a, b; cin >> a >> b;
		cout << RangeQuery(a - 1, b - 1) << "\n";
	}

	return 0;
}