#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
	bool operator()(const int a, const int b) const
	{
		return abs(a) > abs(b)
			|| abs(a) == abs(b) && a > b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	priority_queue<int, vector<int>, Compare> pq;

	int N; cin >> N;
	while(N--)
	{
		int n; cin >> n;
		if (n == 0)
		{
			if (pq.empty()) cout << 0;
			else
			{
				cout << pq.top();
				pq.pop();
			}
			cout << "\n";
		}
		else pq.emplace(n);
	}

	return 0;
}