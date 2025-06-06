#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<int> v(N);
    for(int& i : v)
    {
        cin >> i;
    }
    
    sort(v.begin(), v.end());
    
    for(const int& i : v)
    {
        cout << i << "\n";
    }
    
    return 0;
}