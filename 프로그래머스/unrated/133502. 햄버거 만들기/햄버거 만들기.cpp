#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    string pattern = "1231";
    string str;
    for(const auto& i : ingredient)
        str += char(i + '0');
    
    int answer = 0;
    int pos = 0;
    while(true) {
        const auto p = str.find(pattern, pos);
        if (p == std::string::npos)
            break;
        
        str.erase(p, 4);
        if (p > 2)
            pos = p - 3;
        answer++;
    }
    return answer;
}