#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int begin = 0, end = 10000;
    int answer = 0;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        
        int count = 0;
        for(const auto& citation : citations) {
            if(citation >= mid)
                count++;
        }
        
        if(count >= mid) {
            answer = mid;
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return answer;
}