#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString, string pat) {
    auto pos = 0;
    while(myString.find(pat, pos) != string::npos) {
        pos = myString.find(pat, pos) + pat.length();
    }
    string answer = myString.substr(0, pos);
    return answer;
}