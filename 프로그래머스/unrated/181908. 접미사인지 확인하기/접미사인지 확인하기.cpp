#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
    if(my_string.length() < is_suffix.length())
        return 0;
    
    reverse(my_string.begin(), my_string.end());
    reverse(is_suffix.begin(), is_suffix.end());
    
    for(int i = 0; i < is_suffix.length(); i++) {
        if(my_string[i] != is_suffix[i])
            return 0;
    }
    return 1;
}