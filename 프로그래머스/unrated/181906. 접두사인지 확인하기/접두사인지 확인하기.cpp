#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    for(int i = 0; i < is_prefix.length(); i++) {
        if(my_string[i] != is_prefix[i])
            return 0;
    }
    return 1;
}