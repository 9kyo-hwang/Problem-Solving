#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> Arr1, vector<int> Arr2) 
{
    vector<string> Answer;
    for(int i = 0; i < n; ++i)
    {
        int x1 = Arr1[i], x2 = Arr2[i];
        string Decryption{};
        for(int j = 0; j < n; ++j)
        {
            if(((x1 >> j) | (x2 >> j)) & 1)
            {
                Decryption += '#';
            }
            else
            {
                Decryption += ' ';
            }
        }
        Answer.emplace_back(string(Decryption.rbegin(), Decryption.rend()));
    }
    return Answer;
}