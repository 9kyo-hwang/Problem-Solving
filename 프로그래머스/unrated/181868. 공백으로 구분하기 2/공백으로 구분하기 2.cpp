#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    istringstream ss(my_string);
    string buffer;
    vector<string> answer;
    while(ss >> buffer)
        answer.emplace_back(buffer);
    return answer;
}