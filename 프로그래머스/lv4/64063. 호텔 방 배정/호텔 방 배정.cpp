#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> parents;
ll Find(const ll &x) {
    if(parents[x] == 0) {
        parents[x] = x + 1;
        return x;
    }
    
    return parents[x] = Find(parents[x]);
}

vector<ll> solution(long long k, vector<ll> room_number) {
    vector<ll> answer;
    for(const ll &room : room_number)
        answer.emplace_back(Find(room));
    return answer;
}