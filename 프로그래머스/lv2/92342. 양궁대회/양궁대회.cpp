#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> cases; // 각 점수 별로 라이언이 어피치를 이겼는 지 졌는 지 기록
vector<bool> selected;

void product(const vector<bool> &iterable, const int repeat, int index = 0)
{
    if(index == repeat)
    {
        cases.emplace_back();
        for(int i = 0; i < repeat; i++)
        {
            cases.back().emplace_back(selected[i]);
        }
        return;
    }
    
    for(const auto &elem : iterable)
    {
        selected[index] = elem;
        product(iterable, repeat, index + 1);
    }
}

vector<int> solution(int n, vector<int> info) 
{
    const int repeat = info.size();
    selected.assign(repeat, false);
    product({true, false}, repeat);
    
    vector<int> answer(repeat, 0);
    vector<int> tmp(repeat, 0); // 임시적으로 라이언이 쓴 화살 개수를 기록하는 배열
    int max_diff = 0;
    for(const auto &did_ryan_win : cases)
    {
        int ryan = 0, apeach = 0, cnt = 0;
        for(int i = 0; i < 10; i++)
        {
            if(did_ryan_win[i])
            {
                ryan += 10 - i;
                tmp[i] = info[i] + 1;  // 어피치가 쓴 개수 + 1
                cnt += tmp[i];  // 사용한 화살 개수
            }
            else
            {
                tmp[i] = 0; // 라이언이 지는 경우: 라이언이 맞춘 개수 <= 어피치가 맞춘 개수 -> 0개 맞춤으로 설정
                if(info[i] > 0) apeach += 10 - i;  // 라이언이 하나도 못맞췄기 때문에 어피치가 한 발 이상 맞춘 경우에만 점수를 받을 수 있음.
            }
        }
        
        // n개를 초과해서 화살을 사용하면 안됨.
        if(cnt > n) continue;
        
        tmp[10] = n - cnt; // n개 중 남은 화살은 전부 빗나감 처리
        if(ryan - apeach > max_diff) // 최대 점수 차이 갱신
        {
            max_diff = ryan - apeach;
            answer = tmp;
        }
        else if(ryan - apeach == max_diff)
        {
            for(int i = 10; i >= 0; i--)
            {
                if(tmp[i] > answer[i]) // 낮은 점수를 더 많이 맞춘 경우 갱신
                {
                    answer = tmp;
                    break;
                }
                else if(tmp[i] < answer[i]) // 이미 낮은 점수가 더 많은 경우라면 더 순회할 필요 없음
                {
                    break;
                }
            }
        }
    }
    
    if(max_diff == 0) return {-1};
    return answer;
}