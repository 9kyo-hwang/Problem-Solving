#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<string>> BookTime) 
{
    priority_queue<vector<string>, vector<vector<string>>, greater<>> CheckInQ(BookTime.begin(), BookTime.end());
    priority_queue<string, vector<string>, greater<>> RentQ;
    
    auto TimeParser = [&](const string& Time) -> int
    {
        return stoi(Time.substr(0, 2)) * 60 + stoi(Time.substr(3));
    };
    
    while(!CheckInQ.empty())
    {
        const vector<string> CheckIn = CheckInQ.top();
        const string Start = CheckIn[0], End = CheckIn[1];
        CheckInQ.pop();
        
        if(RentQ.empty())
        {
            RentQ.emplace(End);
            continue;
        }
        
        const string EarliestCheckOutTime = RentQ.top();
        
        if(TimeParser(EarliestCheckOutTime) + 10 <= TimeParser(Start))
        {
            RentQ.pop();
        }
        
        RentQ.emplace(End);
    }
    
    return RentQ.size();
}