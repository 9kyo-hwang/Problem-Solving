#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> nicknames;    
    vector<pair<string, string>> v; // enter/leave, id
    string mod, id, name;
    
    for(const string &str : record)
    {
        istringstream ss(str);        
        ss >> mod >> id >> name;
        
        if(mod != "Leave") nicknames[id] = name;
        if(mod == "Enter" || mod == "Leave") v.emplace_back(mod, id);
    }
    
    vector<string> answer;
    for(const auto &[mod, id] : v)
    {
        if(mod == "Enter") answer.emplace_back(nicknames[id] + "님이 들어왔습니다.");
        else if(mod == "Leave") answer.emplace_back(nicknames[id] + "님이 나갔습니다.");
    }
    return answer;
}