#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

struct Edge {
	int town1, town2, sign, fee;

	Edge(int x, int y, int z, int w) : town1(x), town2(y), sign(z), fee(w) {}

	bool operator<(const Edge& obj) const {
		return sign == obj.sign ? fee > obj.fee : sign > obj.sign;
	}
};

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
	
	priority_queue<Edge> pq;
	int x, y, z, w;
	while (M--) {
		cin >> x >> y >> z >> w;
		pq.emplace(x, y, z, w);
	}

	WQUPC wqupc(N);
	string num = ""; long long cost = 0;
	int num_edge = 0;

	while (!pq.empty()) {
		auto [town1, town2, sign, fee] = pq.top();
		pq.pop();

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