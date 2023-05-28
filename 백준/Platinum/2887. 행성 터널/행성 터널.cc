#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using PlanetPtr = struct Planet*;

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
};

struct Planet
{
	int Index;
	int X, Y, Z;

	Planet(int i, int a, int b, int c) : Index(i), X(a), Y(b), Z(c)
	{
		
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N;
	cin >> N;

	WQUPC unionFtn(N);
	vector<PlanetPtr> planets(N);
	vector<tuple<int, int, int>> edges; // distance, xIndex, yIndex

	for(int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		planets[i] = new Planet(i, a, b, c);
	}

	// sorting by X coordinate
	sort(planets.begin(), planets.end(),
		[](const PlanetPtr p, const PlanetPtr q)
		{
			return p->X < q->X;
		}
	);

	for (int i = 0; i < N - 1; i++)
	{
		const int dist = abs(planets[i]->X - planets[i + 1]->X);
		edges.emplace_back(dist, planets[i]->Index, planets[i + 1]->Index);
	}

	// sorting by Y coordinate
	sort(planets.begin(), planets.end(),
		[](const PlanetPtr p, const PlanetPtr q)
		{
			return p->Y < q->Y;
		}
	);

	for (int i = 0; i < N - 1; i++)
	{
		const int dist = abs(planets[i]->Y - planets[i + 1]->Y);
		edges.emplace_back(dist, planets[i]->Index, planets[i + 1]->Index);
	}

	// sorting by Z coordinate
	sort(planets.begin(), planets.end(),
		[](const PlanetPtr p, const PlanetPtr q)
		{
			return p->Z < q->Z;
		}
	);

	for (int i = 0; i < N - 1; i++)
	{
		const int dist = abs(planets[i]->Z - planets[i + 1]->Z);
		edges.emplace_back(dist, planets[i]->Index, planets[i + 1]->Index);
	}

	sort(edges.begin(), edges.end());

	int mst = 0;
	for (const auto& edge : edges)
	{
		if (auto [d, x, y] = edge; !unionFtn.IsCycle(x, y))
		{
			unionFtn.Union(x, y);
			mst += d;
		}
	}

	cout << mst;

	return 0;
}