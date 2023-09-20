#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

constexpr int OFF_RATES[4] = {10, 20, 30, 40};

vector<int> selected;
vector<vector<int>> off_2d;

void product(const int repeat, int index = 0)
{
    if(index == repeat)
    {
        off_2d.emplace_back();
        for(int i = 0; i < repeat; i++)
        {
            off_2d.back().emplace_back(selected[i]);
        }
        return;
    }
    
    for(const auto &OFF : OFF_RATES)
    {
        selected[index] = OFF;
        product(repeat, index + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    const int repeat = emoticons.size();
    selected.assign(repeat, 0);
    product(repeat);
    
    vector<pii> v;
    for(const auto &off_1d: off_2d)
    {
        int num_sub = 0, sales = 0;
        for(const auto &user: users)
        {
            int user_off = user[0], user_price = user[1];
            bool is_sub = false; int sum_price = 0;
            
            for(int i = 0; i < repeat; i++)
            {
                int off = off_1d[i], price = emoticons[i];
                
                if(off >= user_off)
                {
                    sum_price += (price - price * (off / 100.0));
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