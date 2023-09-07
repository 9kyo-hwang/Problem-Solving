#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> dict;
    for(char ch = 'A'; ch <= 'Z'; ch++)
        dict[to_string(ch)] = ch - 'A' + 1;
    
    int index = 27;
    vector<int> answer;
    for(int i = 0; i < msg.length(); i++)
    {
        string str = to_string(msg[i]);
        int j;
        for(j = i + 1; j < msg.length(); j++)
        {
            if(dict[str + msg[j]] == 0) break;
            str += msg[j];
        }
        
        dict[str + msg[j]] = index++;
        answer.emplace_back(dict[str]);
        i = j - 1;
    }
    return answer;
}