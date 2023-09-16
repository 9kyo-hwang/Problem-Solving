#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

const vector<pair<string, string>> scale_map = {
    {"C#", "c"},
    {"D#", "d"},
    {"F#", "f"},
    {"G#", "g"},
    {"A#", "a"},
};

string replace_all(const string &str, const string &pattern, const string &replace)
{
    string result = str;
    string::size_type pos = 0;
    string::size_type offset = 0;
    
    while((pos = result.find(pattern, offset)) != string::npos)
    {
        result.replace(result.begin() + pos, result.begin() + pos + pattern.length(), replace);
        offset = pos + replace.length();
    }
    
    return result;
}

string replace_sheet(const string &sheet)
{
    string result = sheet;
    for(const auto &[from, to] : scale_map)
    {
        result = replace_all(result, from, to);
    }
    
    return result;
}

tuple<pair<int, int>, string, string> parser(const string &musicinfo)
{
    istringstream ss(musicinfo); string buffer;
    vector<string> v;
    while(getline(ss, buffer, ',')) v.emplace_back(buffer);
    
    int bt = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
    int et = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
    
    string title = v[2];
    string sheet = replace_sheet(v[3]);
    
    return {{bt, et}, title, sheet};
}

string solution(string m, vector<string> musicinfos) 
{
    string answer = "(None)";
    
    m = replace_sheet(m);
    int max_play_time = 0;
    
    for(const string &musicinfo : musicinfos)
    {
        const auto &[times, title, sheet] = parser(musicinfo);
        const auto &[begin, end] = times;
        
        int len = end - begin;
        string str;
        
        // 음수와 소수점을 고려해 max 함수 구성
        for(int i = 0; i < max(1, 1 + len / (int)sheet.length()); i++)
            str += sheet;
        
        str = str.substr(0, len); // 초과 부분에 대해 컷
        
        if(str.find(m) != string::npos && max_play_time < len) // 조건에 부합하며 가장 길게 재생된 음악일 경우
        {
            max_play_time = len;
            answer = title;
        }
    }
    
    return answer;
}