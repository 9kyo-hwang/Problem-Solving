#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;

	vector<int> p(N, 0);
	for (auto& i : p) cin >> i;
	sort(p.begin(), p.end());

	vector<int> sum(N, 0); sum[0] = p[0];
	for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + p[i];

	int min = 0;
	for (const auto i : sum) min += i;

	cout << min;

	return 0;
}