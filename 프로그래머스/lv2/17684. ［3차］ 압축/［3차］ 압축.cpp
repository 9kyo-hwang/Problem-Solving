#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) 
{
    unordered_map<string, int> dict;
    for(char ch = 'A'; ch <= 'Z'; ch++) dict[to_string(ch)] = ch - 'A' + 1;
    int index = 27;
    
    vector<int> answer; int i = 0;
    while(i < msg.length())
    {
        string str = to_string(msg[i]);
        int j = i + 1;
        while(j < msg.length() && dict[str + msg[j]] != 0)
        {
            str += msg[j];
            j++;
        }
        
        dict[str + msg[j]] = index; index++;
        answer.emplace_back(dict[str]);
        i = j;
    }
    
//     for(int i = 0; i < msg.length(); i++)
//     {
//         string str = to_string(msg[i]);
//         int j = i + 1;
//         while(j < msg.length() && dict[str + msg[j]] != 0) str += msg[j++];
        
//         dict[str + msg[j]] = index++;
//         answer.emplace_back(dict[str]);
//         i = j - 1;
//     }
    return answer;
}