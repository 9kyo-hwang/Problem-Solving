#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
	UnionFind(int n)
	{
		p.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i;
		s.resize(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = 1;
	}
	~UnionFind() = default;

	bool unite(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u == v) return false;

		if (s[u] > s[v])
		{
			p[v] = u;
			s[u] += s[v];
		}
		else
		{
			p[u] = v;
			s[v] += s[u];
		}
		return true;
	}

private:
	vector<int> p, s;
	
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<char> univs(N + 1);
	for (int i = 1; i <= N; i++) cin >> univs[i];

	vector<tuple<int, pair<int, char>, pair<int, char>>> edges(M);
	for (auto& [d, u, v] : edges)
	{
		auto& [ui, us] = u; // i: index, s: sex
		auto& [vi, vs] = v;

		cin >> ui >> vi >> d;
		us = univs[ui];
		vs = univs[vi];
	}

	sort(edges.begin(), edges.end());

	UnionFind uf(N);

	int num_edge = 0, sum_dist = 0;
	for (const auto& [d, u, v] : edges)
	{
		const auto& [ui, us] = u;
		const auto& [vi, vs] = v;

		if (us != vs && uf.unite(ui, vi))
		{
			num_edge += 1;
			sum_dist += d;
		}
	}

	if (num_edge < N - 1) cout << -1;
	else cout << sum_dist;

	return 0;
}