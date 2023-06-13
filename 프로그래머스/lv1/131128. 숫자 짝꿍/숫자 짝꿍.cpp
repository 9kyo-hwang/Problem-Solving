#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    string answer = "";
    int i = 0, j = 0;
    while(i < X.length() && j < Y.length()) {
        if(X[i]  - '0' < Y[j] - '0') {
            i++;
        } else if(X[i] - '0' > Y[j] - '0') {
            j++;
        } else {
            answer += X[i];
            i++;
            j++;
        }
    }
    
    if(answer.empty())
        return "-1";
    
    if(answer.find_first_not_of('0') == string::npos)
        return "0";
    
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}