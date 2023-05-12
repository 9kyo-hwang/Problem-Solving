#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    vector<bool> skiped(26, false);
    for(const auto& ch : skip)
        skiped[ch - 'a'] = true;
    
    for(auto &ch : s) {
        int step_count = 0;
        int idx = (ch - 'a' + 1) % 26;
        //cout << ch << ", " << char(idx + 'a') << "\n";
        while(true) {
            if(!skiped[idx])
                step_count++;
            
            if(step_count >= index)
                break;
            
            idx = (idx + 1) % 26;
            //cout << " -- " << step_count << " " << char(idx + 'a') << "\n";
        }
        ch = idx + 'a';
        //cout << " ---- " << char(idx + 'a') << "\n";
    }
    
    return s;
}