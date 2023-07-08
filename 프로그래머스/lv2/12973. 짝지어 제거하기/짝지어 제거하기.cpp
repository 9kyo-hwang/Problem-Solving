#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> stack;
    
    for(const auto &ch : s) {
        if(!stack.empty() && stack.back() == ch) {
            stack.pop_back();
        } else {
            stack.emplace_back(ch);
        }
    }
    
    return stack.empty();
}