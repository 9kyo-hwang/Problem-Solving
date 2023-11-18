#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    vector<string> answer;
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), back_inserter(answer));
    
    return answer[0];
}