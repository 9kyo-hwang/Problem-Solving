#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> kv; // key-value
    unordered_map<int, string> vk; // value-key
    
    int index = 1;
    for(const auto &player : players) {
        kv[player] = index;
        vk[index] = player;
        
        index++;
    }
    
    for(const auto &callee : callings) {
        int order = kv[callee];
        const string& target = vk[order - 1];
        
        swap(kv[callee], kv[target]);
        swap(vk[order], vk[order - 1]);
    }
    
    vector<string> answer(players.size());
    for(const auto &[player, order] : kv) {
        answer[order - 1] = player;
    }
    return answer;
}