#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    int w = 3, h = 3;
    for(int i = sqrt(sum); i >= 3; i--) {
        if(sum % i == 0) {
            w = max(i, sum / i);
            h = min(i, sum / i);
            
            if((w - 2) * (h - 2) == yellow)  // 검증 추가. 테두리를 제외한 영역 개수가 yellow와 같은 지 확인
                break;
        }
    }
    
    return {w, h};
}