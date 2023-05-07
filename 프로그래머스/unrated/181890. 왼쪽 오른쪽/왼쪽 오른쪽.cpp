#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    int i = 0;
    for(const auto& str : str_list) {
        if(str == "l" || str == "r")
            break;
        i++;
    }
    
    if(i >= str_list.size())
        return vector<string>(0);
    
    if(str_list[i] == "l")
        return vector<string>(str_list.begin(), str_list.begin() + i);
    
    if(str_list[i] == "r")
        return vector<string>(str_list.begin() + i + 1, str_list.end());
}