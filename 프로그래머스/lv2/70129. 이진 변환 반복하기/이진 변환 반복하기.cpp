#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    int turn = 0;
    int dist = 0;
    while(true) {
        if(s == "1")
            break;
        
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
    
    answer[0] = turn, answer[1] = dist;
    return answer;
}