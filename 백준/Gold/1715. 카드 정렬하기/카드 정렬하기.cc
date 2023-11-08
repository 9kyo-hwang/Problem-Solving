#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;
	priority_queue<int, vector<int>, greater<>> pq;
	while (N--) {
		int n; cin >> n;
		pq.emplace(n);
	}

	int answer = 0;
	while (!pq.empty()) {
		int A = pq.top(); pq.pop();

		if (pq.empty())
			break;

		int B = pq.top(); pq.pop();

		answer += A + B;
		pq.emplace(A + B);
	}

	cout << answer;

	return 0;
}