#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    for(int i = 0; i < s; i++)
        answer.push_back(my_string[i]);
    for(int i = e; i >= s; i--)
        answer.push_back(my_string[i]);
    for(int i = e + 1; i < my_string.length(); i++)
        answer.push_back(my_string[i]);
    return answer;
}