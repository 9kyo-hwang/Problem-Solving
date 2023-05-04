#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(string myString) {
    stringstream ss(myString);
    string buffer;
    vector<int> answer;
    while(getline(ss, buffer, 'x')) {
        answer.emplace_back(buffer.length());
    }
    if(buffer.empty())
        answer.emplace_back(0);
    return answer;
}