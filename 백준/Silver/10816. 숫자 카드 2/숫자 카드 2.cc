#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, n; // num of cards
    cin >> N;

    vector<int> v(20000001, 0);
    for(auto i = 0; i < N; i++) {
        cin >> n;
        v[n + 10000000]++;
    }

    int M, m;
    cin >> M;
    for(auto i = 0; i < M; i++) {
        cin >> m;
        cout << v[m + 10000000] << " ";
    }

    return 0;
}