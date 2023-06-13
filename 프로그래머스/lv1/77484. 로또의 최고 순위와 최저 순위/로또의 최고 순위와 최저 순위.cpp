#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int correct_cnt = 0;
    for(int i = 0; i < 6; i++) {
        if(lottos[i] == 0)
            continue;
        
        for(int j = 0; j < 6; j++) {
            if(lottos[i] == win_nums[j]) {
                correct_cnt += 1;
                break;
            }
        }
    }
    
    int zero_cnt = std::count(lottos.begin(), lottos.end(), 0);
    return {min(6 - (correct_cnt + zero_cnt) + 1, 6), min(6 - correct_cnt + 1, 6)};
}