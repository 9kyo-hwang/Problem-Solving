#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_balanced(const string& str) {
    stack<char> s;

    bool balanced = true;
    for(auto c : str) {
        if(!balanced) break;

        if(c == '(' || c == '[')
            s.push(c);
        else if(c == ')' || c == ']') {
            if(s.empty()) {
                balanced = false;
                break;
            }

            char top = s.top();
            s.pop();
            if((c == ')') != (top == '(') || (c == ']') != (top == '['))
                balanced = false;
        }
    }

    return balanced && s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string buffer;
    while(getline(cin, buffer)) {
        if(buffer == ".")
            break;
    
        if(is_balanced(buffer))
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }

    return 0;
}