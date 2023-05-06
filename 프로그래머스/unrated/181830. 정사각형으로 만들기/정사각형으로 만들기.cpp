#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int sizeof2d = arr.size(), sizeof1d = arr[0].size();
    if(sizeof2d > sizeof1d) { // 행 > 열
        for(auto& v : arr)
            for(int i = 0; i < sizeof2d - sizeof1d; i++)
                v.emplace_back(0);
    } else if(sizeof1d > sizeof2d) { // 열 > 행
        for(int i = 0; i < sizeof1d - sizeof2d; i++)
            arr.emplace_back(vector<int>(sizeof1d, 0));
    }
    return arr;
}