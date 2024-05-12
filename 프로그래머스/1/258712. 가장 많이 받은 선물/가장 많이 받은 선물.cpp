#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<string> Friends, vector<string> Gifts) 
{
    int FriendIndex = 0;
    unordered_map<string, int> FriendIndices;
    for(const string& Friend : Friends)
    {
        FriendIndices[Friend] = FriendIndex++;
    }
    
    vector<vector<int>> GiftTable(Friends.size(), vector(Friends.size(), 0));
    vector<int> GiveTable(Friends.size(), 0), ReceiveTable(Friends.size(), 0);
    for(const string& Gift : Gifts)
    {
        size_t Pos = Gift.find(' ');
        string Giver = Gift.substr(0, Pos);
        string Receiver = Gift.substr(Pos + 1);
        
        GiftTable[FriendIndices[Giver]][FriendIndices[Receiver]]++;
        GiveTable[FriendIndices[Giver]]++;
        ReceiveTable[FriendIndices[Receiver]]++;
    }
    
    vector<int> NumGiftsToReceive(Friends.size(), 0);
    for(int i = 0; i < Friends.size() - 1; ++i)
    {
        for(int j = i + 1; j < Friends.size(); ++j)
        {
            const auto& FstGive = GiftTable[i][j];
            const auto& SndGive = GiftTable[j][i];
            
            if(FstGive > SndGive)
            {
                NumGiftsToReceive[i]++;
            }
            else if(FstGive < SndGive)
            {
                NumGiftsToReceive[j]++;
            }
            else
            {
                const auto& FstScore = GiveTable[i] - ReceiveTable[i];
                const auto& SndScore = GiveTable[j] - ReceiveTable[j];

                if(FstScore > SndScore)
                {
                    NumGiftsToReceive[i]++;
                }
                else if(FstScore < SndScore)
                {
                    NumGiftsToReceive[j]++;
                }
            }
        }
    }
    
    return *max_element(NumGiftsToReceive.begin(), NumGiftsToReceive.end());
}