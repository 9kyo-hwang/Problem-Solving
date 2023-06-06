#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	const size_t len = N - K;

	string num;
	cin >> num;

	vector<int> v;

	for(const auto &ch : num)
	{
		while(true)
		{
			if(v.empty() || v.back() >= ch - '0' || K <= 0)
			{
				if (v.size() < len)
					v.emplace_back(ch - '0');
				break;
			}
			v.pop_back();
			K--;
		}
	}

	for (const auto& i : v)
		cout << i;

	return 0;
}