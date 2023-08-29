#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, S;
	cin >> N >> S;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	unordered_map<int, int> map;
	long long cnt = 0;
	function<void(int, int, bool)> powerset = [&](int index, int sum, bool flag) {
		if (flag && index == N / 2) {
			map[sum]++;
			return;
		}
		else if (!flag && index == N) {
			cnt += map[S - sum];
			return;
		}

		powerset(index + 1, sum, flag);
		powerset(index + 1, sum + v[index], flag);
		};

	powerset(0, 0, true);
	powerset(N / 2, 0, false);

	if (S == 0)
		--cnt;
	cout << cnt;

	return 0;
}