#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

constexpr int INF = 1e9;
using FNode = pair<int, int>;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;

    vector<int> EnergyofAnts(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> EnergyofAnts[i];
    }

    vector<vector<pair<int, int>>> Tree(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c; cin >> a >> b >> c;

        Tree[a].emplace_back(b, c);
        Tree[b].emplace_back(a, c);
    }

    priority_queue<FNode, vector<FNode>, greater<>> PQ;
    vector<int> Distances(n + 1, INF);
    vector<int> Parents(n + 1, 0);

    PQ.emplace(0, 1);
    Distances[1] = 0;

    while (!PQ.empty())
    {
        const auto [du, u] = PQ.top();
        PQ.pop();

        if (Distances[u] < du) continue;

        for (const auto& [v, dv] : Tree[u])
        {
            if (du + dv < Distances[v])
            {
                Distances[v] = du + dv;
                Parents[v] = u;
                PQ.emplace(Distances[v], v);
            }
        }
    }

    vector<int> Answer(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (i == 0 || i == 1) continue;
        if (Tree[i].size() != 1) continue;

        int Node = i;
        deque<pair<int, int>> Paths;

        while (Node != 0)
        {
            Paths.emplace_back(Node, Distances[Node]);
            Node = Parents[Node];
        }

        while (!Paths.empty())
        {
            const auto [u, du] = Paths.front();
            if (Answer[u] != 0)
            {
                Paths.pop_front();
                continue;
            }

            int Lower = -1, Upper = Paths.size();
            while (Lower + 1 < Upper)
            {
                int Mid = (Lower + Upper) / 2;

                if (Paths[0].second - Paths[Mid].second <= EnergyofAnts[u])
                {
                    Lower = Mid;
                }
                else
                {
                    Upper = Mid;
                }
            }

            if (Lower == -1)
            {
                Answer[u] = Paths[0].first;
            }
            else
            {
                Answer[u] = Paths[Lower].first;
            }

            Paths.pop_front();
        }
    }

    for (int Node = 1; Node <= n; ++Node)
    {
        cout << Answer[Node] << "\n";
    }

    return 0;
}