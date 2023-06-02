#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size() - 1; i++) {
        int count = 0;
        for(int j = i + 1; j < prices.size(); j++) {
            if(prices[i] > prices[j]) {
                if(count == 0)
                    count = 1;
                break;
            }
            count++;
        }
        answer.emplace_back(count);
    }
    answer.emplace_back(0);
    return answer;
}