#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() > arr2.size())
        return 1;
    if(arr1.size() < arr2.size())
        return -1;
    
    if(accumulate(arr1.begin(), arr1.end(), 0) > accumulate(arr2.begin(), arr2.end(), 0))
        return 1;
    if(accumulate(arr1.begin(), arr1.end(), 0) < accumulate(arr2.begin(), arr2.end(), 0))
        return -1;
    
    return 0;
}