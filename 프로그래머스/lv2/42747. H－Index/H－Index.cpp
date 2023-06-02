#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int answer = 0;
    for(int citation = 0; citation < citations.size(); citation++) {
        int h = citations[citation]; // 인용 횟수
        if(h >= citation + 1) { // 인용 횟수 >= 인용된 논문 수라면 H-Index
            answer = citation + 1;
        } else {
            break;
        }
    }
    
    return answer;
}