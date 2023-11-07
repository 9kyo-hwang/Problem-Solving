#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    vector<string> words = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
    };
    
    for(int i = 0; i <= 9; i++) {
        s = regex_replace(s, regex(words[i]), to_string(i));
    }
    
    return stoi(s);
}