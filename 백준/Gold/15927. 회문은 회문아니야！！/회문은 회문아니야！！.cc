#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    string str; cin >> str;
    string rstr = str; reverse(rstr.begin(), rstr.end());
    unordered_set<char> set(str.begin(), str.end());
    
    if(set.size() == 1) {
        cout << -1;
    } else if(str == rstr) {
        cout << str.size() - 1;
    } else {
        cout << str.size();
    }
    
    return 0;
}