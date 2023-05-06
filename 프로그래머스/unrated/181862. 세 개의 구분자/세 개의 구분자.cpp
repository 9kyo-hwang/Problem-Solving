#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    int s = 0;
    while(s < myStr.length()) {
        int e = s;
        while(myStr[e] != 'a' && myStr[e] != 'b' && myStr[e] != 'c')
            e++;
        if(s != e) 
            answer.emplace_back(myStr.substr(s, e - s));
        s = e + 1;
    }
    if(answer.empty())
        answer.emplace_back("EMPTY");
    return answer;
}