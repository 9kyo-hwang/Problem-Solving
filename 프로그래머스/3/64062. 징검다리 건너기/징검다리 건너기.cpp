#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    multiset<pair<int, int>> ms;
    for(int i = 0; i < k; i++) {
        ms.emplace(stones[i], i);
    }
    
    const auto [count, index]= *(--ms.end());
    int answer = count;
    
    for(int i = 0, j = k; j < stones.size(); i++, j++) {
        ms.erase(ms.find({stones[i], i}));
        ms.emplace(stones[j], j);
        
        const auto [count, index] = *(--ms.end());
        answer = min(answer, count);
    }
    
    return answer;
}