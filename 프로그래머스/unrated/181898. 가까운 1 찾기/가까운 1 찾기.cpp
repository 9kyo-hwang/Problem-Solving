#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int index = -1;
    for(int i = idx; i < arr.size(); i++) {
        if(arr[i] == 1) {
            index = i;
            break;
        }
    }
    return index;
}