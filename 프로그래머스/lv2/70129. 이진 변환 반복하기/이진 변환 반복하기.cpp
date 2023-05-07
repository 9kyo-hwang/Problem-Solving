#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int turn = 0;
    int dist = 0;
    
    while(s != "1") {
        auto it = remove(s.begin(), s.end(), '0');
        dist += distance(it, s.end());
        s.erase(it, s.end());
        
        int len = s.length();
        string binary;
        while(len) {
            binary += to_string(len % 2);
            len /= 2;
        }
        s = binary;
        
        turn++;
    }
    
    return {turn, dist};
}