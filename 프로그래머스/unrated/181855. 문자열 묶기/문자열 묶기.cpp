#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> strlen(31, 0);
    for(const auto& str : strArr) {
        strlen[str.length()]++;
    }
    int maxlen = -1;
    for(const auto& i : strlen)
        maxlen = max(i, maxlen);
    return maxlen;
}