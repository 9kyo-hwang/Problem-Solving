#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int num = 1;
    
    while(num <= n * n) {
        while(j < n && arr[i][j] == 0)
            arr[i][j++] = num++;
        j--;
        i++;
        
        while(i < n && arr[i][j] == 0) 
            arr[i++][j] = num++;
        i--;
        j--;
        
        while(j >= 0 && arr[i][j] == 0) 
            arr[i][j--] = num++;
        j++;
        i--;
        
        while(i >= 0 && arr[i][j] == 0)
            arr[i--][j] = num++;
        i++;
        j++;
    }
    
    return arr;
}