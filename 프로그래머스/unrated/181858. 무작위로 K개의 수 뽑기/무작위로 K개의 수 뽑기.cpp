#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    answer.emplace_back(arr[0]);
    
    for(const auto& i : arr) {
        if(answer.size() >= k)
            break;
        
        bool exist = false;
        for(const auto &j : answer) {
            if(i == j) {
                exist = true;
                break;
            }
        }
        
        if(!exist)
            answer.emplace_back(i);
    }
    
    int diff = k - answer.size();
    while(diff--)
        answer.emplace_back(-1);
    
    return answer;
}