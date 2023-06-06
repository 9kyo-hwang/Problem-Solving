#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());
    
  auto it_lost = lost.begin();
  auto it_reserve = reserve.begin();

  while(it_lost != lost.end() && it_reserve != reserve.end()) {
    if(*it_lost < *it_reserve) {
      it_lost++;
    } else if(*it_lost > *it_reserve) {
      it_reserve++;
    } else {
      it_lost = lost.erase(it_lost);
      it_reserve = reserve.erase(it_reserve);
    }
  }
    
  int answer = lost.size();
  int i = 0, j = 0;
  while(i < lost.size() && j < reserve.size()) {
    if(lost[i] < reserve[j] - 1) {
      i++;
    } else if(lost[i] > reserve[j] + 1) {
      j++;
    } else {
      answer--;
      i++;
      j++;
    }
  }
 
    return n - answer;
}