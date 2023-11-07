#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
using Position = pair<int, int>;

unordered_map<int, Position> positionMap = {
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

Position left = {3, 0};
Position right = {3, 2};

char handleLeftNumbers(const int number) {
    left = positionMap[number];
    return 'L';
}

char handleRightNumbers(const int number) {
    right = positionMap[number];
    return 'R';
}

char handleSameDist(const int number, const string &hand) {
    if(hand == "left") {
        left = positionMap[number];
        return 'L';
    } else if(hand == "right") {
        right = positionMap[number];
        return 'R';
    }
    
    return ' '; // exception
}

int calcDist(const Position &p1, const Position &p2) {
    const auto &[y1, x1] = p1;
    const auto &[y2, x2] = p2;
    
    return abs(y2 - y1) + abs(x2 - x1);
}

char handleMiddleNumbers(const int number, const string &hand) {
    const auto &target = positionMap[number];

    int leftDist = calcDist(left, target);
    int rightDist = calcDist(right, target);

    if(leftDist < rightDist) {
        return handleLeftNumbers(number);
    } else if(leftDist > rightDist) {
        return handleRightNumbers(number);
    } else {
        return handleSameDist(number, hand);
    }
}

char handleNumbers(const int number, const string &hand) {
    if(number == 1 || number == 4 || number == 7) {
        return handleLeftNumbers(number);
    } else if(number == 3 || number == 6 || number == 9) {
        return handleRightNumbers(number);
    } else { // 2, 5, 8, 0
        return handleMiddleNumbers(number, hand);
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(const int number : numbers) {
        answer += handleNumbers(number, hand);
    }
    return answer;
}