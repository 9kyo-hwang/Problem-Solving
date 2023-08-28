#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using jewel = pair<int, int>; // mass, value
using ll = long long;

struct Compare {
	bool operator()(const jewel& a, const jewel& b) const {
		if (a.second == b.second) return a.first > b.first;
		return a.second < b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, K;
	cin >> N >> K;

	int m, v;
	priority_queue<jewel, vector<jewel>, Compare> pq;
	while (N--) {
		cin >> m >> v;
		pq.emplace(m, v);
	}

	int c;
	multiset<int> ms;
	while (K--) {
		cin >> c;
		ms.emplace(c);
	}

	ll answer = 0;
	multiset<int>::iterator it;
	while (!pq.empty() && !ms.empty()) {
		const auto [m, v] = pq.top();
		it = ms.lower_bound(m);

		if (it == ms.end()) {
			pq.pop();
			continue;
		}

		answer += v;
		pq.pop();
		it = ms.erase(it);
	}
	cout << answer;

	return 0;
}