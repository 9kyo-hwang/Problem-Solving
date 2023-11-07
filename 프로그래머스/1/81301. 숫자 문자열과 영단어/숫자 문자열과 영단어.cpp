#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, int> wordToNumber = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };
    
    int answer = 0;
    
    string tmp = "";
    for(const char& c : s) {
        if(isdigit(c)) {
            answer = answer * 10 + c - '0';
            tmp.clear();
        } else {
            tmp += c;
            if(wordToNumber.find(tmp) != wordToNumber.end()) {
                answer = answer * 10 + wordToNumber[tmp];
                tmp.clear();
            }
        }
    }
    
    return answer;
}