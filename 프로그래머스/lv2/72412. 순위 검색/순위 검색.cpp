#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) 
{
    unordered_map<string, int> cat = 
    {
        {"cpp", 0}, {"java", 1}, {"python", 2},
        {"backend", 0}, {"frontend", 1},
        {"junior", 0}, {"senior", 1},
        {"chicken", 0}, {"pizza", 1},
    };

    vector<int> table[3][2][2][2];

    for (const auto &str : info) 
    {
        istringstream ss(str); string buffer;
        vector<string> v;

        while (getline(ss, buffer, ' ')) 
            v.emplace_back(buffer);

        table[cat[v[0]]][cat[v[1]]][cat[v[2]]][cat[v[3]]].emplace_back(stoi(v[4]));
    }

    vector<int> result;
    for (const auto &q : query) 
    {
        istringstream ss(q); string buffer;
        vector<string> v;
        
        while (getline(ss, buffer, ' '))
            v.emplace_back(buffer);

        int score = stoi(v[7]);
        int cnt = 0;

        vector<int> range[4];
        if (v[0] == "-") range[0] = {0, 1, 2};
        else range[0] = {cat[v[0]]};

        if (v[2] == "-") range[1] = {0, 1};
        else range[1] = {cat[v[2]]};

        if (v[4] == "-") range[2] = {0, 1};
        else range[2] = {cat[v[4]]};

        if (v[6] == "-") range[3] = {0, 1};
        else range[3] = {cat[v[6]]};

        for (const auto &i : range[0]) 
            for (const auto &j : range[1]) 
                for (const auto &k : range[2]) 
                    for (const auto &l : range[3]) 
                        for (const auto &s : table[i][j][k][l]) 
                            if (s >= score) cnt++;

        result.emplace_back(cnt);
    }
    
    return result;
}