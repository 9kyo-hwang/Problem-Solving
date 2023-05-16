#include <algorithm>
#include <iostream>
#include <vector>

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

		for(int i = 0; i < n; i++)
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
		while(x != P[x])
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

		if(Size[x] < Size[y])
		{
			P[x] = y;
			Size[x] += Size[y];
		}
		else
		{
			P[y] = x;
			Size[y] += Size[x];
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int V, E; // num of vertices/edges
	cin >> V >> E;

	WQUPC unionFtn(V + 1);
	vector<tuple<int, int, int>> edges;

	while(E--)
	{
		int A, B, C; // a to b, weight: c
		cin >> A >> B >> C;

		edges.emplace_back(C, A, B);
	}

	sort(edges.begin(), edges.end());

	int mst = 0;

	for(const auto& edge : edges)
	{
		if(auto [d, x, y] = edge; !unionFtn.IsCycle(x, y))
		{
			unionFtn.Union(x, y);
			mst += d;
		}
	}

	cout << mst << "\n";

	return 0;
}