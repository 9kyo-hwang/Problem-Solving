#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WQUPC // Weighted-Quick Union with Path Compression
{
	int* P;
	int* Size;

public:
	WQUPC(const int n)
	{
		P = new int[n];
		Size = new int[n];

		for (int i = 0; i < n; i++)
		{
			P[i] = i;
			Size[i] = 1;
		}
	}
	~WQUPC()
	{
		delete P;
		delete Size;
	}

	bool IsCycle(const int x, const int y)
	{
		return Find(x) == Find(y);
	}

	int Find(int x)
	{
		while (x != P[x])
		{
			P[x] = P[P[x]];
			x = P[x];
		}

		return P[x];
	}

	void Union(const int u, const int v)
	{
		const int x = Find(u);
		const int y = Find(v);

		if (Size[x] > Size[y])
		{
			P[y] = x;
			Size[x] += Size[y];
		}
		else
		{
			P[x] = y;
			Size[y] += Size[x];
		}
	}

	int GetSize(const int x)
	{
		return Size[x];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while(T--)
	{
		int F;
		cin >> F;

		WQUPC unionFtn(F * 2); // union-find
		unordered_map<string, int> hashMap; // name to index
		string a, b; // names

		int index = 0;
		while(F--)
		{
			cin >> a >> b;

			if (hashMap.find(a) == hashMap.end()) hashMap[a] = index++;
			if (hashMap.find(b) == hashMap.end()) hashMap[b] = index++;

			int x = hashMap[a]; int y = hashMap[b];
			if(!unionFtn.IsCycle(x, y))
				unionFtn.Union(x, y);

			int p = unionFtn.Find(x);
			cout << unionFtn.GetSize(p) << "\n";

		}
	}

	return 0;
}