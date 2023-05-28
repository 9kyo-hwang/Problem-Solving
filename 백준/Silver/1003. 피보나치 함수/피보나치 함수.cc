#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		if(N == 0) cout << 1 << " " << 0 << "\n";
		else if(N == 1) cout << 0 << " " << 1 << "\n";
		else {
			vector<pair<int, int>> cache(N + 1, {0, 0});

			cache[0].first = 1, cache[0].second = 0;
			cache[1].first = 0, cache[1].second = 1;
			for(int i = 2; i <= N; i++) {
				cache[i].first = cache[i-1].first + cache[i-2].first;
				cache[i].second = cache[i-1].second + cache[i-2].second;
			}

			cout << cache[N].first << " " << cache[N].second << "\n";
		}
	}

	return 0;
}