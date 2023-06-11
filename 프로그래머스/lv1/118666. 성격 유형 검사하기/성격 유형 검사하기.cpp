#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int personality[8] = {0,};
    unordered_map<char, int> ctoi;
    ctoi['R'] = 0;
    ctoi['T'] = 1;
    ctoi['C'] = 2;
    ctoi['F'] = 3;
    ctoi['J'] = 4;
    ctoi['M'] = 5;
    ctoi['A'] = 6;
    ctoi['N'] = 7;
    unordered_map<int, char> itoc;
    itoc[0] = 'R';
    itoc[1] = 'T';
    itoc[2] = 'C';
    itoc[3] = 'F';
    itoc[4] = 'J';
    itoc[5] = 'M';
    itoc[6] = 'A';
    itoc[7] = 'N';
    
    for(int i = 0; i < choices.size(); i++) {
        if(choices[i] == 4)
            continue;
        
        if(1 <= choices[i] && choices[i] <= 3) {
            personality[ctoi[survey[i][0]]] += (4 - choices[i]);
        } else if(5 <= choices[i] && choices[i] <= 7) {
            personality[ctoi[survey[i][1]]] += (choices[i] - 4);
        }
    }
    
    string answer = "";
    for(int i = 0; i < 8; i += 2) {
        if(personality[i] >= personality[i + 1]) {
            answer += itoc[i];
        } else {
            answer += itoc[i + 1];
        }
    }
    return answer;
}