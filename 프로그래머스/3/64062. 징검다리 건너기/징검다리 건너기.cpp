#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    multiset<int> ms;
    for(int i = 0; i < k; i++) {
        ms.emplace(stones[i]);
    }
    
    int answer = *(--ms.end());
    
    for(int i = 0, j = k; j < stones.size(); i++, j++) {
        ms.erase(ms.find(stones[i]));
        ms.emplace(stones[j]);
        
        answer = min(answer, *(--ms.end()));
    }
    
    return answer;
}