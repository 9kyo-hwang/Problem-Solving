#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> order;
    for(int i = 0; i < rank.size(); i++) {
        if(!attendance[i])
            continue;
        
        order.emplace_back(rank[i], i);
    }
    
    sort(order.begin(), order.end());
    
    return order[0].second * 10000 + order[1].second * 100 + order[2].second;
}