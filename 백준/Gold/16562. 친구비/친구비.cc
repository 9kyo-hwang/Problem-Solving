#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DisjointSet 
{
public:
	DisjointSet(int n, vector<int> v)
	{
		p.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i;
		c = v;
	}
	~DisjointSet() = default;

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (c[x] > c[y])
		{
			p[x] = y;
			c[x] = c[y];
		}
		else
		{
			p[y] = x;
			c[y] = c[x];
		}
	}

	int get()
	{
		int sum_cost = 0;
		for (int i = 1; i < p.size(); i++)
		{
			int root = find(i);
			if (set.find(root) == set.end())
			{
				set.emplace(root);
				sum_cost += c[root];
			}
		}

		return sum_cost;
	}

private:
	vector<int> p, c;
	unordered_set<int> set;

	int find(int x)
	{
		while (x != p[x])
		{
			p[x] = p[p[x]];
			x = p[x];
		}
		return p[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, k;
	cin >> N >> M >> k;

	vector<int> costs(N + 1);
	for (int n = 1; n <= N; n++)
		cin >> costs[n];

	DisjointSet ds(N, costs);
	
	int src, dst;
	while (M--)
	{
		cin >> src >> dst;
		ds.unite(src, dst);
	}

	int sum_cost = ds.get();
	if (sum_cost > k) cout << "Oh no";
	else cout << sum_cost;

	return 0;
}