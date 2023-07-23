#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    vector<int> counts(10000001, 0);
    for(const int &i : tangerine) {
        counts[i] += 1;
    }
    
    vector<pair<int, int>> v;
    for(int i = 1; i <= 10000000; i += 1) {
        if(counts[i] != 0) {
            v.emplace_back(counts[i], i);
        }
    }
    
    sort(v.begin(), v.end());
    
    int size = v.size(); // num of size type
    int i;
    for(i = size -1 ; i >= 0; i -= 1) {
        const auto &[cnt, idx] = v[i];
        k -= cnt;
        
        if(k <= 0) {
            break;
        }
    }
    
    return size - i;
}