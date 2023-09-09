#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

tuple<pair<int, int>, int, char> parser(const string& record)
{
    istringstream ss(record);
    string buffer;
    
    ss >> buffer;
    int hour = stoi(buffer.substr(0, 2));
    int minute = stoi(buffer.substr(3, 5));
    
    ss >> buffer;
    int car_number = stoi(buffer);
    
    ss >> buffer;
    string history = buffer;
    
    return {{hour, minute}, car_number, history[0]};
}

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<int, pair<int, int>> entrances;
    unordered_map<int, int> accumulates;
    map<int, int> prices;
    vector<int> v(10000, -1);
    
    for(const string &record : records)
    {
        const auto &[t, c, h] = parser(record);
        
        if(h == 'I')
        {
            entrances[c] = t;
        }
        else if(h == 'O')
        {
            const auto [in_h, in_m] = entrances[c];
            entrances.erase(c);
            
            const auto [out_h, out_m] = t;
            
            int time = ((out_h - in_h) * 60 + out_m) - in_m;
            accumulates[c] += time;
        }
    }
    
    for(const auto &[c, t] : entrances)
    {
        const auto &[h, m] = t;
        int time = ((23 - h) * 60 + 59) - m;
        accumulates[c] += ((23 - h) * 60 + 59) - m;
    }
    
    for(const auto &[c, t] : accumulates)
    {
        v[c] = fees[1] + ceil(max((double)(t - fees[0]), 0.0) / fees[2]) * fees[3];
    }
    
    vector<int> answer;
    for(const int i : v)
    {
        if(i != -1) answer.emplace_back(i);
    }
    return answer;
}