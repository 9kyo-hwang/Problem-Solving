#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    int i = 0, j = arr.size() - 1;
    while(i <= j) {
        if(arr[i] == 2 && arr[j] == 2)
            break;
        
        if(arr[i] != 2)
            i++;
        if(arr[j] != 2)
            j--;
    }
    
    if(i > j)
        return vector<int>(1, -1);
    if(i == j)
        return vector<int>(1, 2);
    
    return vector<int>(&arr[i], &arr[j + 1]);
}