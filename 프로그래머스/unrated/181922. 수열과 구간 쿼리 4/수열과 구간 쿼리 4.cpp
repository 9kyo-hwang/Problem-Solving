#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const auto& query : queries) {
        int s = query[0], e = query[1], k = query[2];
        for(int i = s; i <= e; i++) {
            if(i % k == 0)
                ++arr[i];
        }
    }
    return arr;
}