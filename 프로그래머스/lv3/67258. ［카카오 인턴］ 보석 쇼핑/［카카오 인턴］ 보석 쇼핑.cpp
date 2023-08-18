#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
  unordered_map<string, int> map;
  int cur_begin = 0, cur_end = 0;
  int min_begin = cur_begin, min_end = cur_end;
  for(int end = 0; end < gems.size(); end++) {
    map[gems[end]] += 1;

    if(map[gems[end]] == 1) { // 구간 끝점 확장
      cur_end = end;

      min_begin = cur_begin;
      min_end = cur_end;
      continue;
    }

    // 구간 시작점 재설정
    cur_end = end;
    for(int begin = cur_begin; begin < end; begin++) {
      if(map[gems[begin]] == 1) { // 새 시작점 발견
        cur_begin = begin;
        
        if(cur_end - cur_begin < min_end - min_begin) {
          min_begin = cur_begin;
          min_end = cur_end;
        }
        break;
      }

      map[gems[begin]] -= 1;
    }
  }

  return {min_begin + 1, min_end + 1};
}