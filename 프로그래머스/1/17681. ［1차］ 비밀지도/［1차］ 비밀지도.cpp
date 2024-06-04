#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> Arr1, vector<int> Arr2) 
{
    vector<string> Answer;
    for(int i = 0; i < n; ++i)
    {
        int x = Arr1[i] | Arr2[i];
        string Decryption{};
        for(int j = 0; j < n; ++j)
        {
            Decryption += (x & 1 ? '#' : ' ');
            x >>= 1;
        }
        Answer.emplace_back(string(Decryption.rbegin(), Decryption.rend()));
    }
    return Answer;
}