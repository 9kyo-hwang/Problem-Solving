#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> set(nums.begin(), nums.end());
    return min(set.size(), nums.size() / 2);
}