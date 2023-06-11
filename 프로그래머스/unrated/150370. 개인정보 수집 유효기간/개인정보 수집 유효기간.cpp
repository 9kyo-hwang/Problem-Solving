#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <iostream>

using namespace std;

tuple<int, int, int> Parser(const string &str) {
    int y = stoi(str.substr(0, 4)); // year
    int m = stoi(str.substr(5, 7)); // month
    int d = stoi(str.substr(8, 10)); // day
    return {y, m, d};
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    const auto &[year, month, day] = Parser(today);
    
    unordered_map<char, int> term_table;
    for(const auto &term : terms)
        term_table[term[0]] = stoi(term.substr(2));
    
    vector<int> answer;
    int index = 1;
    for(const auto &privacy : privacies) {
        const auto &[y, m, d] = Parser(privacy);
        int t = term_table[privacy[11]];
        
        int ny = y, nm = m + t, nd = d - 1;
        if(nm > 12) {
            while(nm > 12) {
                ny += 1;
                nm -= 12;
            }
            
            if(nm == 0)
                nm = 12;
        }
        if(nd == 0) {
            nd = 28;
            nm -= 1;
            if(nm == 0)
                nm = 12;
        }
        
        if(year > ny || year == ny && month > nm || year == ny && month == nm && day > nd)
            answer.emplace_back(index);
        index++;
    }
    
    return answer;
}