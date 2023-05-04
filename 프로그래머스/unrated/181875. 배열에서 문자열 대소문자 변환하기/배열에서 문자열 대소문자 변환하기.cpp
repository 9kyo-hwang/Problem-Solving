#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    int i = 0;
    for(auto& str : strArr) {
        if(i % 2 == 0) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        } else {
            transform(str.begin(), str.end(), str.begin(), ::toupper);
        }
        i++;
    }
    return strArr;
}