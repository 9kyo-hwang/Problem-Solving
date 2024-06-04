#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> Arr1, vector<int> Arr2) 
{
    vector<string> Answer(n, "");
    for(int i = 0; i < n; ++i)
    {
        int x = Arr1[i] | Arr2[i];
        for(int j = 0; j < n; ++j)
        {
            Answer[i].insert(0, (x & 1 ? "#" : " "));
            x >>= 1;
        }
    }
    return Answer;
}