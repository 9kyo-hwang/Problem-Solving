#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string odd = "", even = "";
    for(const auto i : num_list) {
        if(i % 2 == 1)
            odd += to_string(i);
        else
            even += to_string(i);
    }
    int answer = stoi(odd) + stoi(even);
    return answer;
}