#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

void backtracking(const vector<vector<int>> &dice, map<int, int> &sums, vector<int> &comb, int depth = 0) {
    if(depth == dice.size()) {
        sums[reduce(comb.begin(), comb.end())] += 1;
        return;
    }
    
    for(const int num : dice[depth]) {
        comb.emplace_back(num);
        backtracking(dice, sums, comb, depth + 1);
        comb.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int max_win = 0;
    
    const int n = dice.size();
    vector<bool> v(n / 2, false);
    v.insert(v.end(), n / 2, true);
    do {
        vector<vector<int>> A, B;
        vector<int> A_indices;
        for(int i = 0; i < n; ++i) {
            if(v[i]) {
                A.emplace_back(dice[i]);
                A_indices.emplace_back(i + 1);
                cout << i + 1 << " ";
            } else {
                B.emplace_back(dice[i]);
            }
        }
        
        vector<int> A_comb, B_comb;
        map<int, int> A_sums, B_sums;
        backtracking(A, A_sums, A_comb);
        backtracking(B, B_sums, B_comb);
        
        int win = 0;
        for(const auto &[a_sum, a_cnt] : A_sums) {
            for(const auto &[b_sum, b_cnt] : B_sums) {
                if(b_sum >= a_sum) {
                    break;
                }
                
                win += a_cnt * b_cnt;
            }
        }
        
        if(win > max_win) {
            max_win = win;
            answer = A_indices;
        }
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}