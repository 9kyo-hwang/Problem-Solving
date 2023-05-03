#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int index = num_list.size() - 1;
    if(num_list[index - 1] < num_list[index])
        num_list.emplace_back(num_list[index] - num_list[index - 1]);
    else
        num_list.emplace_back(num_list[index] * 2);
    return num_list;
}