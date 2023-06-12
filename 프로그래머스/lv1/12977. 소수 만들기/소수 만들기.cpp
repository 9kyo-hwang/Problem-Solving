#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int answer = 0;
    for(int i = 0; i < nums.size() - 2; i++) {
        for(int j = i + 1; j < nums.size() - 1; j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                bool is_prime = true;
                for(int x = 2; x <= sqrt(sum); x++) {
                    if(sum % x == 0) {
                        is_prime = false;
                        break;
                    }
                }
                if(is_prime)
                    answer++;
            }
        }
    }
    return answer;
}