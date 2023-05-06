#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(auto pos = 0; myString.find(pat, pos) != string::npos; pos++) {
        pos = myString.find(pat, pos);
        answer++;
    }
    return answer;
}