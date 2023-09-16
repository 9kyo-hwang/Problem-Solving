#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> set;
vector<bool> visited;

bool is_banned(const string &user, const string &ban)
{
    if(user.length() != ban.length()) 
        return false;

    int strlen = user.length();
    for(int i = 0; i < strlen; i++)
    {
        if(ban[i] != '*' && user[i] != ban[i])
            return false;
    }

    return true;
}

void combination(const vector<string> &user_id, const vector<string> &banned_id, const int n, const int k, int index)
{
    if(index == k)
    {
        string comb;
        for(int i = 0; i < n; i++)
        {
            if(visited[i]) 
                comb += user_id[i];
        }
        set.emplace(comb);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] || !is_banned(user_id[i], banned_id[index])) 
            continue;

        visited[i] = true;
        combination(user_id, banned_id, n, k, index + 1);
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{   
    int n = user_id.size();
    int k = banned_id.size();
    visited.assign(n, false);

    combination(user_id, banned_id, n, k, 0);

    return set.size();
}