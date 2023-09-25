#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{   
    while(!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
    while(!pickups.empty() && pickups.back() == 0) pickups.pop_back();
    ll answer = max(deliveries.size(), pickups.size());
    
    while(!deliveries.empty() || !pickups.empty())
    {
        ll capacity = 0;
        while(!deliveries.empty())
        {
            capacity += deliveries.back();
            deliveries.pop_back();
            
            if(capacity > cap)
            {
                deliveries.emplace_back(capacity - cap);
                break;
            }
        }
        
        capacity = 0;
        while(!pickups.empty())
        {
            capacity += pickups.back();
            pickups.pop_back();

            if(capacity > cap)
            {
                pickups.emplace_back(capacity - cap);
                break;
            }
        }
        
        answer += max(deliveries.size(), pickups.size());
    }
    
    return answer * 2; // 왕복이므로
}