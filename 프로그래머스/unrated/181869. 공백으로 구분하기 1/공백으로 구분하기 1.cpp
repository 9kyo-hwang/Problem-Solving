#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    istringstream ss(my_string);
    vector<string> answer;
    string buffer;
    while(ss >> buffer)
        answer.emplace_back(buffer);
    return answer;
}