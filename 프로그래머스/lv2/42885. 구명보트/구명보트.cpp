#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int left = 0, right = people.size() - 1;
    int answer = 0;
    
    while(left <= right) {
        if(left == right) { // last 1
            answer++;
            break;
        }
        
        if(people[left] + people[right] > limit) { // only right
            answer++;
            right--;
        } else { // both
            answer++;
            left++;
            right--;
        }
    }
    return answer;
}