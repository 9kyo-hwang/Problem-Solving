#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool first = true;
    for(auto& c : s) {
        if(c == ' ') {
            first = true;
            continue;
        }
        
        if(first && ('a' > c || c > 'z')) {
            first = false;
        } else if(first && ('a' <= c && c <= 'z')) {
            first = false;
            c -= 32;
        } else if(!first && ('A' <= c && c <= 'Z')) {
            c += 32;
        }
    }
    return s;
}