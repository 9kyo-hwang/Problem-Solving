#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer(&arr[intervals[0][0]], &arr[intervals[0][1] + 1]);
    answer.insert(answer.end(), &arr[intervals[1][0]], &arr[intervals[1][1] + 1]);
    return answer;
}