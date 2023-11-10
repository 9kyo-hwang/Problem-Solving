#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N; cin >> N;
    vector<int> v(N);
    for(int &i : v) cin >> i;
    
    sort(v.begin(), v.end(), greater<>());
    
    int mid = int(v.size() / (double)2 - 0.5);
    int p = reduce(v.begin(), v.begin() + mid + 1);
    int s = reduce(v.begin() + mid + 1, v.end());
    
    cout << s << " " << p;
    return 0;
}