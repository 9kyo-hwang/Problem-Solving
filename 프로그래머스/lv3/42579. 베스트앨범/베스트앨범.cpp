#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> gtoi; // genre to index
    int index = 0;
    for(const auto& genre : genres) {
        if(gtoi[genre] == 0)
            gtoi[genre] = index++;
    }
    
    // [총 재생 수, <고유 번호, 재생 수> 리스트] 리스트
    // unordered_map을 이용해 장르를 숫자로 indexing
    vector<pair<int, vector<pair<int, int>>>> lists(index);
    for(int i = 0; i < plays.size(); i++) {
        auto& [total_play, list] = lists[gtoi[genres[i]]];
        
        total_play += plays[i];
        list.emplace_back(i, plays[i]);
    }
    
    // 재생 총합 수 순으로 장르 정렬
    sort(lists.begin(), lists.end(), greater<>()); 
    // 장르 속에서 재생 횟수가 많은 순, 동일한 경우 고유 번호가 작은 순으로 정렬
    for(auto& [total_play, list] : lists) {
        sort(list.begin(), list.end(), [](const pair<int, int>& p, const pair<int, int>&q) {
            return p.second > q.second || p.second == q.second && p.first < q.first;
        });
    }
    
    vector<int> answer;
    for(const auto& [total_play, list] : lists) {
        int i = 0;
        for(const auto& [id, play] : list) {
            if(i == 2) break;
            
            answer.emplace_back(id);
            i++;
        }
    }
    
    return answer;
}