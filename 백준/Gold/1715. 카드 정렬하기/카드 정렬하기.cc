#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;
	priority_queue<ll, vector<ll>, greater<>> pq;
	while (N--) {
		int n; cin >> n;
		pq.emplace(n);
	}

	ll answer = 0;
	while (!pq.empty()) {
		ll A = pq.top(); pq.pop();

		if (pq.empty())
			break;

		ll B = pq.top(); pq.pop();

		answer += A + B;
		pq.emplace(A + B);
	}

	cout << answer;

	return 0;
}