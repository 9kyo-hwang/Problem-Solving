#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> dictionary;
    for(char ch = 'A'; ch <= 'Z'; ++ch)
        dictionary[string(1, ch)] = ch - 'A' + 1;
    
    vector<int> answer;
    int begin = 0;
    int index = 27;
    while(begin < msg.length()) {
        string str(1, msg[begin]);
        int end = begin + 1;
        while(end < msg.length()) {
            if(dictionary[str + msg[end]] == 0)
                break;
            str += msg[end++];
        }

        dictionary[str + msg[end]] = index++;
        answer.emplace_back(dictionary[str]);
        begin = end;
    }
    
    return answer;
}