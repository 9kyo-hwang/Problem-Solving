#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_correct(const string &u)
{
    vector<char> stack;
    for(const char &ch : u)
    {
        if(ch == '(') stack.emplace_back(ch);
        else
        {
            if(!stack.empty() && stack.back() == '(') stack.pop_back();
            else stack.emplace_back(ch);
        }
    }
    
    return stack.empty();
}

int get_balanced_index(const string &w)
{
    int index = 0;
    int open = 0, close = 0;
    
    for(int i = 0; i < w.length(); i++)
    {
        if(w[i] == '(') open++;
        else close++;
        
        if(open == close)
        {
            index = i + 1;
            break;
        }
    }
    
    return index;
}

string converter(string w)
{
    // 1
    if(w.empty()) return w;
    
    // 2
    int index = get_balanced_index(w);
    string u = w.substr(0, index);
    string v = w.substr(index);
    
    string result;
    if(is_correct(u)) // 3
    {
        // 3-1
        result = u + converter(v);
    }
    else // 4
    {
        result += '('; // 4-1
        result += converter(v); // 4-2
        result += ')'; // 4-3
        
        // 4-4
        u = u.substr(1, u.length() - 2); 
        for(char &ch : u)
        {
            if(ch == '(') ch = ')';
            else ch = '(';
        }
        
        // 4-5
        result += u;
    }
    return result;
}

string solution(string p) {
    return converter(p);
}