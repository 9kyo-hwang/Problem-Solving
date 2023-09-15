#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;
	vector<int> v1(N), v2(N);
	for (int& i : v1) cin >> i;
	for (int& i : v2) cin >> i;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += v1[i] * v2[i];
	}
	cout << sum;

	return 0;
}