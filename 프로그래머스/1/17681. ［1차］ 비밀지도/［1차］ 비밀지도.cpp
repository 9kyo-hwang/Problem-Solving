#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");
    for(int i = 0; i < n; ++i) {
        int x = arr1[i] | arr2[i];
        for(int j = 0; j < n; ++j) {
            answer[i].insert(0, (x & 1 ? "#" : " "));
            x >>= 1;
        }
    }
    return answer;
}