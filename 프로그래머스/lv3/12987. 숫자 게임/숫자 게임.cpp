#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int answer = 0;
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) {
            answer += 1;
            i += 1;
            j += 1;
        } else {
            j += 1;
        }
    }
    return answer;
}