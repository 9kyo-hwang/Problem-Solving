#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Comparator
{
    bool operator()(const string &a, const string &b) const
    {
        if(a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};

set<string, Comparator> candidate_keys;
vector<bool> combination;

bool is_unique(const vector<vector<string>> &relation)
{
    set<string> s;
    for(const auto &relate : relation)
    {
        string str;
        for(int i = 0; i < relation[0].size(); i++)
        {
            if(combination[i]) str += relate[i];
        }
        s.emplace(str);
    }
    
    return s.size() == relation.size();
}

bool is_minimal(const vector<vector<string>> &relation)
{
    string str;
    for(int i = 0; i < relation[0].size(); i++)
    {
        if(combination[i]) str += to_string(i);
    }
    
    for(const auto &candidate_key : candidate_keys)
    {
        int cnt = 0;
        for(const char &ch : str)
        {
            for(const auto &key : candidate_key)
            {
                if(ch == key) cnt++;
            }
        }
        
        if(cnt == candidate_key.length()) return false;
    }

    return true;
}

int solution(vector<vector<string>> relation) 
{
    int num_student = relation.size();
    int n = relation[0].size(); // num of column
    
    for(int k = 1; k <= n; k++)
    {
        combination.assign(n - k, false);
        combination.insert(combination.end(), k, true);
        
        do
        {
            if(!is_unique(relation) || !is_minimal(relation)) continue;
            
            string candidate_key;
            for(int i = 0; i < n; i++)
            {
                if(combination[i]) candidate_key += to_string(i);
            }

            candidate_keys.emplace(candidate_key); 
            
        } while(next_permutation(combination.begin(), combination.end()));
    }

    return candidate_keys.size();
}