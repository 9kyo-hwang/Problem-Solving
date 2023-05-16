#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int num_id = id_list.size();
    
    unordered_map<string, int> str_to_int;
    for(int i = 0; i < num_id; i++)
        str_to_int[id_list[i]] = i;
    
    vector<vector<bool>> is_report(num_id, vector<bool>(num_id, false));
    vector<int> num_reported(num_id, 0);
    
    string src, dest;
    for(const auto& str : report) {
        istringstream ss(str);
        ss >> src >> dest;
        int src_idx = str_to_int[src];
        int dest_idx = str_to_int[dest];
        
        if(!is_report[src_idx][dest_idx]) {
            is_report[src_idx][dest_idx] = true;
            num_reported[dest_idx]++;
        }
    }
    
    vector<int> answer(num_id, 0);
    for(int c = 0; c < num_id; c++) {
        if(num_reported[c] < k)
            continue;
        
        for(int r = 0; r < num_id; r++) {
            if(is_report[r][c])
                answer[r]++;
        }
    }
    return answer;
}