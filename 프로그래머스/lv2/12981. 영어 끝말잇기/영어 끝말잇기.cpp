#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, int> map;
    
    string prev = words[0];
    map[words[0]] = 1;
    for(int i = 1; i < n; i++) {
        if(words[i].front() != prev.back() || map[words[i]] != 0) {
            return {i + 1, 1};
        }
        map[words[i]] = 1;
        prev = words[i];
    }
    
    int step = 2;
    for(int i = n; i < words.size(); i += n) {
        for(int j = 0; j < n; j++) {
            if(prev.back() != words[i + j].front() || map[words[i + j]] != 0) {
                return {j + 1, step};
            }
            map[words[i + j]] = 1;
            prev = words[i + j];
        }
        step += 1;
    }
    
    return {0, 0};
}