#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using GroupPtr = struct Group*;

constexpr int MAX = 1'000'000'001;

struct Group
{
	int MinNum{}, MaxNum{};
	vector<int> Data;
};

int N, M, G, Q;
vector<GroupPtr> v;

pair<int, int> RangeQuery(const int i, const int j)
{
	const int iGroup = i / M;
	const int iIndex = i % M;
	const int jGroup = j / M;
	const int jIndex = j % M;

	int minNum = MAX, maxNum = 0;

	if (iGroup == jGroup)
	{
		for (int index = iIndex; index <= jIndex; index++)
		{
			minNum = min(minNum, v[iGroup]->Data[index]);
			maxNum = max(maxNum, v[iGroup]->Data[index]);
		}
		return {minNum, maxNum};
	}

	for (int index = iIndex; index < M; index++)
	{
		minNum = min(minNum, v[iGroup]->Data[index]);
		maxNum = max(maxNum, v[iGroup]->Data[index]);
	}

	for (int group = iGroup + 1; group < jGroup; group++)
	{
		minNum = min(minNum, v[group]->MinNum);
		maxNum = max(maxNum, v[group]->MaxNum);
	}

	for (int index = 0; index <= jIndex; index++)
	{
		minNum = min(minNum, v[jGroup]->Data[index]);
		maxNum = max(maxNum, v[jGroup]->Data[index]);
	}

	return { minNum, maxNum };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> Q;

	M = static_cast<int>(floor(sqrt(N)));
	G = static_cast<int>(ceil(static_cast<double>(N) / M));

	for (int i = 0; i < G; i++)
	{
		auto group = new struct Group;

		int minNum = MAX, maxNum = 0;
		for (int j = 0; j < M && N > 0; j++)
		{
			int n; cin >> n;
			group->Data.emplace_back(n);
			N--;

			minNum = min(minNum, n);
			maxNum = max(maxNum, n);
		}

		group->MinNum = minNum;
		group->MaxNum = maxNum;
		v.emplace_back(group);
	}

	while (Q--)
	{
		int a, b; cin >> a >> b;
		auto [fst, snd] = RangeQuery(a - 1, b - 1);
		cout << fst << " " << snd << "\n";
	}

	return 0;
}