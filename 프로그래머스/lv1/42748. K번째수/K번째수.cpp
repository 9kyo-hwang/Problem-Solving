#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(const auto& command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> tmp(&array[i - 1], &array[j]);
        sort(tmp.begin(), tmp.end());
        answer.emplace_back(tmp[k - 1]);
    }
    return answer;
}