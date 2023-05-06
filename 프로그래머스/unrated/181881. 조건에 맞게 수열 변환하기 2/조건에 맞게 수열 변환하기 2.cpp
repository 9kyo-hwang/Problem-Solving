#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int arrlen = arr.size();
    int answer = 0;
    
    while(true) {
        vector<int> tmp = arr;
        for(auto& i : arr) {
            if(i >= 50 && i % 2 == 0)
                i /= 2;
            else if(i < 50 && i % 2 == 1)
                i = i * 2 + 1;
        }
        
        bool is_same = true;
        for(int i = 0; i < arrlen; i++) {
            if(tmp[i] != arr[i]) {
                is_same = false;
                break;
            }
        }
        
        if(is_same)
            break;
        
        answer++;
    }
    
    return answer;
}