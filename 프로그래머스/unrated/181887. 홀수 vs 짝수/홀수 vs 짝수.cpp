#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    int i = 0;
    for(const auto &num : num_list) {
        if(i % 2 == 0)
            odd += num;
        else
            even += num;
        i++;
    }
    return max(odd, even);
}