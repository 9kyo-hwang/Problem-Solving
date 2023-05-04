#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for(const auto& i : arr) {
        bool flag = false;
        for(const auto& j : delete_list) {
            if(i == j) {
                flag = true;
                break;
            }
        }
        if(!flag)
            answer.emplace_back(i);
    }
    return answer;
}