#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int row = arr.size(), col = arr[0].size();
    int size = max(row, col);
    for(auto& v : arr)
        v.resize(size, 0); // 원본 크기가 size보다 작다면 수행되지 않음
    arr.resize(size, vector<int>(size, 0));
    return arr;
}