#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void QueueClear(queue<pair<string, int>> &q)
{
	queue<pair<string, int>> empty;
	swap(q, empty);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	bool visited[20001];
	queue<pair<string, int>> q;

	int T, N;
	cin >> T;

	while(T--)
	{
		QueueClear(q);
        fill_n(visited, 20001, false);

		cin >> N;

		if(N == 1)
		{
			cout << N << "\n";
			continue;
		}

		string result = "BRAK";

		q.emplace("1", 1);

		while (!q.empty())
		{
			auto [str, num] = q.front();
			q.pop();

			for (int i = 0; i <= 1; i++)
			{
				int next = (num * 10 + i) %	N;

				if (visited[next]) continue;

				if (next == 0)
				{
					result = str + to_string(i);
					break;
				}

				visited[next] = true;
				q.emplace(str + to_string(i), next);
			}
		}

		cout << result << "\n";
	}

	return 0;
}