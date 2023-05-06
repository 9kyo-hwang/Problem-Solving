#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    while(arr.size() & arr.size() - 1)
        arr.emplace_back(0);
    return arr;
}