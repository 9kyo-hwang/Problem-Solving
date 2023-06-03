#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<int> nums;
vector<int> remain(10, 0);
int len_num = 0;
unordered_set<int> set;

bool IsPrime(int n) {
  if(n <= 1)
    return false;

  for(int i = 2; i <= sqrt(n); i++) {
    if(n % i == 0)
      return false;
  }

  return true;
}

int GetPrimeNum(int num = 0, int count = 0) {
  if(count == len_num) {
    if(set.find(num) != set.end())
      return 0;

    set.emplace(num);
    return IsPrime(num);
  }

  int num_prime = 0;
  for(const auto& i : nums) {
    if(remain[i] == 0)
      continue;

    remain[i]--;
    num_prime += GetPrimeNum(num * 10 + i, count + 1);
    remain[i]++;
  }

  return num_prime;
}

int solution(string numbers) {
    for(const auto& ch : numbers) {
        nums.emplace_back(ch - '0');
        remain[ch - '0']++;
    }
    
    int answer = 0;
    for(int i = 1; i <= nums.size(); i++) {
        len_num = i;
        answer += GetPrimeNum();
    }
    return answer;
}