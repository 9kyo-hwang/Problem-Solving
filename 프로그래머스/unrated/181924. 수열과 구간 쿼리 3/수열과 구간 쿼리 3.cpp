#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const auto& q : queries) {
        int i = q[0], j = q[1];
        swap(arr[i], arr[j]);
    }
    return arr;
}