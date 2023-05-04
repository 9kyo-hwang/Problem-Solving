#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    for(int i = 0; i < my_strings.size(); i++) {
        int s = parts[i][0], e = parts[i][1];
        for(int j = s; j <= e; j++) {
            answer.push_back(my_strings[i][j]);
        }
    }
    return answer;
}