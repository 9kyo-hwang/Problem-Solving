#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<pair<double, double>> P(N);
    for(auto& [x, y] : P)
    {
        cin >> x >> y;
    }
    
    const auto& [x0, y0] = P[0];
    double Area = 0.0;
    
    for(int i = 1; i < N - 1; ++i)
    {
        const auto& [x1, y1] = P[i];
        const auto& [x2, y2] = P[i + 1];
        
        Area += ((x0 * y1 + x1 * y2 + x2 * y0 - y0 * x1 - y1 * x2 - y2 * x0) / 2.0);
    }
    
    cout << fixed;
    cout.precision(1);
    cout << abs(Area);
    
    return 0;
}