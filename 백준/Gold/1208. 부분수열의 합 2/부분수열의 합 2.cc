#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

int N, S;
vector<int> v;
unordered_map<int, int> map;
long long cnt = 0;

void powerset(int index, int sum, bool flag) {
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
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;

	v.resize(N);
	for (int& i : v)
		cin >> i;

	powerset(0, 0, true);
	powerset(N / 2, 0, false);

	if (S == 0)
		--cnt;
	cout << cnt;

	return 0;
}