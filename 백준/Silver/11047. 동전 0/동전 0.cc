#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> coin(N);

	for (auto& i : coin) cin >> i;

	int count = 0;
	for(auto it = coin.rbegin(); it != coin.rend(); ++it)
	{
		count += K / *it; // 나눈 몫만큼 개수 증가
		K %= *it; // K를 몫으로 나눈 나머지로 갱신
		// K < *it인 경우 몫이 0이고 나머지도 원본 값 그대로 유지됨
	}

	cout << count << "\n";

	return 0;
}