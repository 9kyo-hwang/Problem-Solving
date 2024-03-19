#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    
    auto IsItConsistent = [](const vector<string>& PhoneNumbers)
    {
        for(int i = 0; i < PhoneNumbers.size() - 1; ++i)
        {
            if(PhoneNumbers[i].size() < PhoneNumbers[i + 1].size() 
            && PhoneNumbers[i] == PhoneNumbers[i + 1].substr(0, PhoneNumbers[i].size()))
            {
                return false;
            }
        }
        return true;
    };
    
    while(T--)
    {
        int N; cin >> N;
        vector<string> PhoneNumbers(N);
        for(string& PhoneNumber : PhoneNumbers)
        {
            cin >> PhoneNumber;
        }
        
        sort(PhoneNumbers.begin(), PhoneNumbers.end());
        
        if(IsItConsistent(PhoneNumbers))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}