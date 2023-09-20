#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

constexpr int DISCOUNT_RATES[4] = {10, 20, 30, 40};
vector<int> selected;
vector<vector<int>> rates_arr;

void product(const int repeat, int r = 0)
{
    if(r == repeat)
    {
        rates_arr.emplace_back();
        for(int i = 0; i < repeat; i++)
        {
            rates_arr.back().emplace_back(selected[i]);
        }
        return;
    }
    
    for(const auto &rate : DISCOUNT_RATES)
    {
        selected[r] = rate;
        product(repeat, r + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    const int repeat = emoticons.size();
    selected.assign(repeat, 0);
    product(repeat);
    
    vector<pii> v;
    for(const auto &rates: rates_arr)
    {
        int num_sub = 0, sales = 0;
        for(const auto &user : users)
        {
            int user_rate = user[0], user_price = user[1];
            bool is_sub = false; int sum_price = 0;
            
            for(int i = 0; i < repeat; i++)
            {
                int rate = rates[i], price = emoticons[i];
                
                if(rate >= user_rate)
                {
                    sum_price += (price - price * (rate / 100.0));
                }
                
                if(sum_price >= user_price)
                {
                    is_sub = true;
                    break;
                }
            }
            
            if(is_sub) num_sub++;
            else sales += sum_price;
        }
        
        v.emplace_back(num_sub, sales);
    }
    
    sort(v.begin(), v.end(), [](const pii &a, const pii &b)
         {
             if(a.first == b.first) return a.second > b.second;
             return a.first > b.first;
         });
    
    
    return {v[0].first, v[0].second};
}