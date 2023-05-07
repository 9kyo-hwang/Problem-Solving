#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if(s[0] == '-')
        return -1 * stoi(string(s.begin() + 1, s.end()));
    
    return stoi(s);
}