#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;
using edge = tuple<pair<int, int>, int, int>;

class WQUPC {
public:
	WQUPC(int n) {
		init(n);
	}
	~WQUPC() = default;

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y)
			return false;

		if (size[x] > size[y]) {
			parent[y] = x;
			size[x] += size[y];
		}
		else {
			parent[x] = y;
			size[y] += size[x];
		}
		return true;
	}

private:
	vector<int> parent, size;

	void init(int n) {
		parent = vector<int>(n + 1);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
		size = vector<int>(n + 1, 1);
	}

	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return parent[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<edge> edges(M);
	for (auto& [p, z, w] : edges) {
		auto& [x, y] = p;
		cin >> x >> y >> z >> w;
	}

	sort(edges.begin(), edges.end(), [](const edge& lhs, const edge& rhs) {
		const auto& [p1, z1, w1] = lhs;
		const auto& [p2, z2, w2] = rhs;
		return z1 == z2 ? w1 < w2 : z1 < z2;
		});

	WQUPC wqupc(N);
	string num = ""; long long cost = 0;
	int num_edge = 0;

	for (const auto& [pos, sign, fee] : edges) {
		const auto& [town1, town2] = pos;
		if (wqupc.unite(town1, town2)) {
			num += to_string(sign);
			cost += fee;
			num_edge += 1;
		}
	}

	if (num_edge != N - 1) cout << -1;
	else cout << num << " " << cost;

	return 0;
}