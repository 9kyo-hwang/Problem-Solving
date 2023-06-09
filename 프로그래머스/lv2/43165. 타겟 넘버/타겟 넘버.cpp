#include <string>
#include <vector>

using namespace std;

int DFS(vector<int>& numbers, int number, int target, int index, int count) {
    if(index >= numbers.size())
        return number == target;
    
    return DFS(numbers, number + numbers[index], target, index + 1, count + 1) 
        + DFS(numbers, number - numbers[index], target, index + 1, count + 1);
}

int solution(vector<int> numbers, int target) {
    return DFS(numbers, 0, target, 0, 0);
}