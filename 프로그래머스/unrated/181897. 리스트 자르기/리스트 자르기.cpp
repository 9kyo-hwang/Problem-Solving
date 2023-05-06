#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int a = slicer[0], b = slicer[1], c = slicer[2];
    switch(n) {
        case 1: answer = vector<int>(&num_list[0], &num_list[b + 1]); break;
        case 2: answer = vector<int>(&num_list[a], &num_list[num_list.size()]); break;
        case 3: answer = vector<int>(&num_list[a], &num_list[b + 1]); break;
        case 4: {
            for(int i = a; i <= b; i += c)
                answer.emplace_back(num_list[i]);
            break;
        }
    }
    return answer;
}