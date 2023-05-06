#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> order) {
    unordered_map<string, int> map;
    map["iceamericano"] = 4500;
    map["americanoice"] = 4500;
    map["hotamericano"] = 4500;
    map["americanohot"] = 4500;
    map["icecafelatte"] = 5000;
    map["cafelatteice"] = 5000;
    map["hotcafelatte"] = 5000;
    map["cafelattehot"] = 5000;
    map["americano"] = 4500;
    map["cafelatte"] = 5000;
    map["anything"] = 4500;
    
    int answer = 0;
    
    for(const auto& str : order) {
        answer += map[str];
    }
    return answer;
}