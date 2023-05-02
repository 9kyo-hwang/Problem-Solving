#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    for(const auto i : num_list) {
        if (i == n) {
            return 1;
        }
    }
    return 0;
}