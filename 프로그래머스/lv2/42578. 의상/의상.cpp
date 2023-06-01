#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, vector<string>> map;
    for(const auto& v : clothes)
        map[v[1]].emplace_back(v[0]);
    
    int answer = 1;
    for(const auto& [category, dresses] : map)
        answer *= dresses.size() + 1; // +1: 입느냐, 안입느냐
    
    return answer - 1; // 아무것도 안입는 경우 제외
}