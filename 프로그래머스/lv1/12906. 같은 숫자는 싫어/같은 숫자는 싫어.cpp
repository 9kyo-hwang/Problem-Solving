#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(const auto& i : arr) {
        if(answer.empty() 
           || answer[answer.size() - 1] != i)
            answer.emplace_back(i);
    }
    return answer;
}