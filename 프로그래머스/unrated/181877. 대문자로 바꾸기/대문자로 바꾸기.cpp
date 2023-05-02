#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    int interval = 'a' - 'A';
    for(auto& ch : myString) {
        if('a' <= ch && ch <= 'z')
            ch -= interval;
    }
    string answer = myString;
    return answer;
}