#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<string>> BookTime) 
{
    priority_queue<vector<string>, vector<vector<string>>, greater<>> CheckInQ(BookTime.begin(), BookTime.end());
    priority_queue<vector<string>, vector<vector<string>>, greater<>> CheckOutQ;
    
    auto TimeParser = [&](const string& Time) -> int
    {
        return stoi(Time.substr(0, 2)) * 60 + stoi(Time.substr(3));
    };
    
    while(!CheckInQ.empty())
    {
        const vector<string> InTime = CheckInQ.top();
        const string InStart = InTime[0], InEnd = InTime[1];
        CheckInQ.pop();
        
        if(CheckOutQ.empty())
        {
            CheckOutQ.push({InEnd, InStart});
            continue;
        }
        
        const vector<string> OutTime = CheckOutQ.top();
        const string OutStart = OutTime[1], OutEnd = OutTime[0];
        
        if(TimeParser(OutEnd) + 10 <= TimeParser(InStart))
        {
            CheckOutQ.pop();
        }
        
        CheckOutQ.push({InEnd, InStart});
    }
    
    return CheckOutQ.size();
}