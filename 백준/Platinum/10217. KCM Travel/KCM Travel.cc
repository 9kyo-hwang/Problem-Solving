#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
typedef struct node {
	int V; int cost; int time;
};
vector<node> adj[102];
typedef struct Node {
	int V; int time;
};
typedef struct cmp {
	bool operator()(Node& a, Node& b) {
		return a.time > b.time;
	}
};
priority_queue<Node, vector<Node>, cmp> pq;
int dist[102][10002];
void dijkstra(int M, int N) {
	pq.push({ 1,0 });//출발지 1 도착지 N //(dist[1][j] = 0)
	while (pq.size()) {
		Node pop = pq.top(); pq.pop();
		if (dist[pop.V][M] < pop.time)continue;//해당 정점에서 M비용 이하로 최소 시간으로 갔다면 그 이상으로 온것은 볼필요 없다!
		for (int s = 0;s < adj[pop.V].size();s++) {
			int arrive = adj[pop.V][s].V;
			int time = adj[pop.V][s].time;
			int C = adj[pop.V][s].cost;
			int pre = dist[arrive][M];
			for (int k = 0;k <= M;k++) {
				if (k + C > M)break;
				if (dist[pop.V][k] == INF)continue;//pop.V M에서만 check했기 때문에 여기서도 한번 더 거른다!
				if (dist[pop.V][k] + time < dist[arrive][k + C])dist[arrive][k + C] = dist[pop.V][k] + time;
			}
			if (pre > dist[arrive][M])pq.push({ arrive,dist[arrive][M] });
		}
	}
	if (dist[N][M] == INF)cout << "Poor KCM\n";
	else cout << dist[N][M] << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, N, M, K, u, v, c, d;//공항의 수 N
	cin >> T;
	for (int tc = 0;tc < T;tc++) {
		cin >> N >> M >> K;
		//초기화
		while (pq.size()) { pq.pop(); }
		for (int i = 1;i <= N;i++) {
			for (int j = 0;j <= M;j++) {
				if (i == 1)dist[i][j] = 0;//출발지 1
				else dist[i][j] = INF;
			}
			adj[i].clear();
		}

		for (int i = 0;i < K;i++) {
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v,c,d });
		}
		dijkstra(M, N);
	}
}