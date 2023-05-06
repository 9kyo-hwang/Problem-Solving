#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(const auto& query: queries) {
        int s = query[0], e = query[1], k = query[2];
        int min_ceil = 1000001;
        for(int i = s; i <= e; i++) {
            if(arr[i] > k && arr[i] < min_ceil)
                min_ceil = arr[i];
        }
        min_ceil = min_ceil == 1000001 ? -1 : min_ceil;
        answer.emplace_back(min_ceil);
    }
    
    return answer;
}