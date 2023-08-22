#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class WQUPC {
public:
	WQUPC(int n) {
		init(n);
	}
	~WQUPC() = default;

	bool unionftn(int x, int y) {
		x = findftn(x);
		y = findftn(y);

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

	int findftn(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return parent[x];
	}
};

struct Edge {
	int town1 = 0, town2 = 0, fee = 0;
	string sign = "";

	Edge(int x, int y, string z, int w) : town1(x), town2(y), sign(z), fee(w) {}

	bool operator<(const Edge& obj) const {
		return (sign + obj.sign < obj.sign + sign) || ((sign + obj.sign == obj.sign + sign) && (fee < obj.fee));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	int x, y, w; string z;
	vector<Edge> edges;

	while (M--) {
		cin >> x >> y >> z >> w;

		edges.emplace_back(x, y, z, w);
	}

	sort(edges.begin(), edges.end());
	WQUPC wqupc(N);

	string num; long long cost = 0;
	int num_edge = 0;
	for (auto [town1, town2, fee, sign] : edges) {
		if (wqupc.unionftn(town1, town2)) {
			num += sign;
			cost += fee;
			num_edge += 1;
		}
	}

	if (num_edge != N - 1) cout << -1;
	else cout << num << " " << cost;

	return 0;
}