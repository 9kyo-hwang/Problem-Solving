#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {    
    unordered_map<int, int> counts;
    for(const int &i : tangerine) {
        counts[i] += 1;
    }
    
    vector<pair<int, int>> v;
    for(int i = 0; i < counts.size(); i += 1) {
        v.emplace_back(counts[i], i + 1);
    }
    
    sort(v.begin(), v.end());
    
    int size = v.size(); // num of size type
    int i;
    for(i = size - 1; i >= 0; i -= 1) {
        const auto &[cnt, idx] = v[i];
        k -= cnt;
        
        if(k <= 0) {
            break;
        }
    }
    
    return size - i;
}