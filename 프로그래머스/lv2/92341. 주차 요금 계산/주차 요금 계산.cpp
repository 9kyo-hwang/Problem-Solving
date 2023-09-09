#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

tuple<pair<int, int>, int, string> parser(const string& record)
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
    
    return {{hour, minute}, car_number, history};
}

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<int, pair<int, int>> entrances;
    unordered_map<int, int> accumulates;
    map<int, int> prices;
    
    for(const string &record : records)
    {
        const auto &[t, c, h] = parser(record);
        
        if(h == "IN")
        {
            entrances[c] = t;
        }
        else if(h == "OUT")
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
    
    int base_time = fees[0], base_fee = fees[1], unit_time = fees[2], unit_fee = fees[3];
    for(const auto &[c, t] : accumulates)
    {
        prices[c] = base_fee + ceil(max((double)(t - base_time), 0.0) / unit_time) * unit_fee;
    }
    
    vector<int> answer;
    for(const auto &[c, f] : prices) answer.emplace_back(f);
    return answer;
}