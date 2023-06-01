#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> books) {
    unordered_set<string> set(books.begin(), books.end());
    
    for(const auto& str : books) {
        string prefix = "";
        for(const auto& ch : str) {
            prefix += ch;
            
            if(prefix == str)
                continue;
            
            if(set.find(prefix) != set.end())
                return false;
        }
    }
    
    return true;
}