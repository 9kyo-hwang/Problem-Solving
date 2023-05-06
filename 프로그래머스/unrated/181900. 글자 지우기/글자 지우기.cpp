#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    for(const auto& i : indices)
        my_string[i] = ' ';
    
    string answer = "";
    for(const auto &ch : my_string) {
        if(ch != ' ')
            answer.push_back(ch);
    }
    return answer;
}