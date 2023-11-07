#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, pair<int, int>> handPosMap = 
{
    {1, {0, 0}},
    {2, {0, 1}},
    {3, {0, 2}},
    {4, {1, 0}},
    {5, {1, 1}},
    {6, {1, 2}},
    {7, {2, 0}},
    {8, {2, 1}},
    {9, {2, 2}},
    {0, {3, 1}},
};

string solution(vector<int> numbers, string hand) 
{
    pair<int, int> leftPos = {3, 0};
    pair<int, int> rightPos = {3, 2};

    string answer = "";
    for(const int number : numbers) 
    {
        switch(number) 
        {
            case 1:
            case 4:
            case 7: 
                {
                    leftPos = handPosMap[number];
                    answer += 'L';
                    break;
                }
            case 3:
            case 6:
            case 9: 
                {
                    rightPos = handPosMap[number];
                    answer += 'R';
                    break;
                }
            case 2:
            case 5:
            case 8:
            case 0:
                {
                    const auto &[cy, cx] = handPosMap[number];
                    const auto &[ly, lx] = leftPos;
                    const auto &[ry, rx] = rightPos;
                    
                    int leftDist = abs(ly - cy) + abs(lx - cx);
                    int rightDist = abs(ry - cy) + abs(rx - cx);
                    
                    if(leftDist < rightDist)
                    {
                        leftPos = handPosMap[number];
                        answer += 'L';
                        break;
                    }
                    else if(leftDist > rightDist)
                    {
                        rightPos = handPosMap[number];
                        answer += 'R';
                        break;
                    }
                    else
                    {
                        if(hand == "left")
                        {
                            leftPos = handPosMap[number];
                            answer += 'L';
                            break;
                        }
                        else if(hand == "right")
                        {
                            rightPos = handPosMap[number];
                            answer += 'R';
                            break;
                        }
                    }
                }
            default: break;
        }
    }
    
    return answer;
}