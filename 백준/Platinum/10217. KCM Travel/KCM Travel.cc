#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<functional>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 10000;
const int INF = 0x3f3f3f3f;
int N, M, K;
int dist[MAX_N + 1][MAX_M + 1];
vector<tuple<int, int, int> > adj[MAX_N + 1];

bool CmpCost(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<1>(a) < get<1>(b);
}

void init() {
    for (int i = 0; i <= N; i++) {
        adj[i] = {};
    }
    memset(dist, 0x3f, sizeof(dist));
}

int dijkstra(int st) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
    dist[st][0] = 0;
    pq.push({ dist[st][0], 0, st });
    while (!pq.empty()) {
        const auto [cur_dist, cur_cost, cur_idx] = pq.top(); pq.pop();

        if (dist[cur_idx][cur_cost] != cur_dist) continue;

        for (const auto& [d, c, v] : adj[cur_idx]) {
            int nxt_dist = cur_dist + d;
            int nxt_cost = cur_cost + c;
            int nxt_idx = v;

            if (nxt_cost > M) break;

            if (nxt_dist < dist[nxt_idx][nxt_cost]) {
                for (int i = nxt_cost; i <= M; i++) {
                    if (dist[nxt_idx][i] <= nxt_dist) break;
                    dist[nxt_idx][i] = nxt_dist;
                }
                pq.push({ dist[nxt_idx][nxt_cost], nxt_cost, nxt_idx });
            }
        }
    }
    
    int ret = INF;
    for (int i = 0; i <= M; i++) {
        ret = min(ret, dist[N][i]);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test_case; cin >> test_case;
    while (test_case--) {
        init();
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            int u, v, c, d; cin >> u >> v >> c >> d;
            adj[u].emplace_back( d, c, v );
        }
        for (int i = 1; i <= N; i++) {
            sort(adj[i].begin(), adj[i].end(), CmpCost);
        }
        int ans = dijkstra(1);
        if (ans >= INF) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }

    return 0;
}