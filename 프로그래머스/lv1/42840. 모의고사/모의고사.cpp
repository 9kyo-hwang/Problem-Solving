#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> guess[3];
    guess[0] = {1, 2, 3, 4, 5}; // 5개 반복
    guess[1] = {2, 1, 2, 3, 2, 4, 2, 5}; // 8개 반복
    guess[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10개 반복
    
    pair<int, int> score[3] = {
        {0, 1},
        {0, 2},
        {0, 3}
    };
    
    int i = 0, j = 0, k = 0;
    for(const auto& answer : answers) {
        if(guess[0][i] == answer)
            score[0].first++;
        if(guess[1][j] == answer)
            score[1].first++;
        if(guess[2][k] == answer)
            score[2].first++;
        
        i = (i + 1) % 5;
        j = (j + 1) % 8;
        k = (k + 1) % 10;
    }
    
    sort(score, score + 3);
    
    if(score[0].first == score[1].first && score[1].first == score[2].first)
        return {score[0].second, score[1].second, score[2].second};
    
    if(score[1].first == score[2].first)
        return {score[1].second, score[2].second};
    
    return {score[2].second};
}