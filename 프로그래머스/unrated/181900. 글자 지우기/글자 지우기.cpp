#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    vector<bool> flag(my_string.length(), false);
    for(const auto &i : indices)
        flag[i] = true;
    
    string answer = "";
    for(int i = 0; i < my_string.length(); i++)
        if(!flag[i])
            answer.push_back(my_string[i]);
    return answer;
}