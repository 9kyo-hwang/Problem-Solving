#include <iostream>
#include <vector>

using namespace std;

int get_order(vector<pair<int, int>> &v, int M) {
    int count = 1;
    while(true) {
        bool higher = false;
        for(auto i = 1; i < v.size(); i++) {
            if(v[i].second > v[0].second) {
                v.emplace_back(v[0]);
                v.erase(v.begin());
                higher = true;
                break;
            }
        }

        if(higher) continue;

        if(v[0].first == M)
            break;

        v.erase(v.begin());
        count++;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N, M; // num of document, order of target
        cin >> N >> M;

        vector<pair<int, int>> v(N); // index, level
        for(auto i = 0; i < N; i++) {
            int n;
            cin >> n;
            v.emplace_back(i, n);
        }

        int order = get_order(v, M);
        cout << order << "\n";
    }

    return 0;
}