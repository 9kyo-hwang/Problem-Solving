#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N; cin >> N;
    vector<int> v(N);
    for(int &i : v) cin >> i;
    
    sort(v.begin(), v.end());
    cout << v[int(v.size() / (double)2 - 0.5)];
    
    return 0;
}