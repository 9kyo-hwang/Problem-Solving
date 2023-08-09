#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solution(int n, vector<int> v) {
    vector<ll> times(v.begin(), v.end());
    ll min_time = 1, max_time = times.back() * n;
    
    ll answer = 0;
    while(min_time <= max_time) {
        ll avg_time = (min_time + max_time) / 2;
        ll passed_cnt = 0;
        
        for(const ll &t : times) {
            passed_cnt += avg_time / (ll)t;
        }
        
        if(passed_cnt >= n) {
            max_time = avg_time - 1;
            answer = avg_time;
        } else {
            min_time = avg_time + 1;
        }
    }
    

    return answer;
}