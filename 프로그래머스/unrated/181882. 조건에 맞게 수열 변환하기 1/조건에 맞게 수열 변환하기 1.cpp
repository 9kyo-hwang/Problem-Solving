#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for(auto &i : arr) {
        if(i >= 50 && i % 2 == 0)
            i /= 2;
        else if(i < 50 && i % 2 == 1)
            i *= 2;
    }
    return arr;
}