#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    bool balanced = true;
    
    for(const auto& c : s) {
        if(!balanced)
            break;
        
        if(c == '(')
            st.emplace(c);
        else if(c == ')') {
            if(st.empty()) {
                balanced = false;
                break;
            }
            
            st.pop();
        }
    }
    
    return balanced && st.empty();
}