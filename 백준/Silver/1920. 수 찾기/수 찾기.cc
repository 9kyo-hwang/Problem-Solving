#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M, n, m;
    cin >> N;
    
    vector<int> v(N);
    for(int &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    cin >> M;
    while(M--) {
        cin >> m;
        cout << binary_search(v.begin(), v.end(), m) << "\n";
    }
}