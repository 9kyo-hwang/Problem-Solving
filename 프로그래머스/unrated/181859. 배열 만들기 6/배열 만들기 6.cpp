#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    for(const auto& i : arr) {
        if(stk.empty())
            stk.emplace_back(i);
        else {
            if(stk.back() == i)
                stk.pop_back();
            else
                stk.emplace_back(i);
        }
    }
    
    if(stk.empty())
        stk.emplace_back(-1);
    return stk;
}