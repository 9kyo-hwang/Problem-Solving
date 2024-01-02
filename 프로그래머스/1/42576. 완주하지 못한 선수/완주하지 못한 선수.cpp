#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> pmap, cmap;
    for(const auto &str : participant) {
        pmap[str] += 1;
    }
    for(const auto &str : completion) {
        cmap[str] += 1;
    }
    
    string answer = "";
    for(const auto &[k, v] : pmap) {
        if(cmap.find(k) == cmap.end() || cmap[k] - v != 0) {
            answer = k;
            break;
        }
    }
    return answer;
}