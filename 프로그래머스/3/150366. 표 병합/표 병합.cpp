#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <iostream>

using namespace std;

const int R = 50, C = 50;
vector<string> table;
vector<int> parents;

inline int convert(int r, int c) {
    return r * C + c;
}

int find(int x) {
    while(x != parents[x]) {
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return parents[x];
}

void unite(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    
    if(table[root_x] == "EMPTY") {
        parents[root_x] = root_y;
        for(int i = 0; i < R * C; ++i) {
            if(parents[i] == root_x) {
                parents[i] = root_y;
            }
        }
    } else {
        parents[root_y] = root_x;
        for(int i = 0; i < R * C; ++i) {
            if(parents[i] == root_y) {
                parents[i] = root_x;
            }
        }
    }
}

string PRINT(const vector<string>& v) {
    int r = stoi(v[1]) - 1, c = stoi(v[2]) - 1;
    return table[find(convert(r, c))];
}

void UNMERGE(const vector<string>& v) {
    int r = stoi(v[1]) - 1, c = stoi(v[2]) - 1;
    int parent = find(convert(r, c));
    string content = table[parent];
    
    for(int i = 0; i < R * C; ++i) {
        if(parents[i] == parent) {
            parents[i] = i;
            table[i] = "EMPTY";
        }
    }
    
    table[convert(r, c)] = content;
}

void MERGE(const vector<string>& v) {
    int r1 = stoi(v[1]) - 1, c1 = stoi(v[2]) - 1, r2 = stoi(v[3]) - 1, c2 = stoi(v[4]) - 1;
    unite(convert(r1, c1), convert(r2, c2));
}

void UPDATE(const vector<string>& v) {
    if(v.size() == 4) {
        int r = stoi(v[1]) - 1, c = stoi(v[2]) - 1;
        string value = v[3];
        
        table[find(convert(r, c))] = value;
    } else if(v.size() == 3) {
        string value1 = v[1], value2 = v[2];
        for(int i = 0; i < R * C; ++i) {
            if(table[i] == value1) {
                table[i] = value2;
            }
        }
    }
}

vector<string> solution(vector<string> commands) {
    table.assign(R * C, "EMPTY");
    parents.resize(R * C);
    iota(parents.begin(), parents.end(), 0);
    
    vector<string> answer;
    for(const string& command : commands) {
        istringstream ss(command);
        string buffer; vector<string> v;
        while(ss >> buffer) {
            v.emplace_back(buffer);
        }
        
        if(v[0] == "UPDATE") {
            UPDATE(v);
        } else if(v[0] == "MERGE") {
            MERGE(v);
        } else if(v[0] == "UNMERGE") {
            UNMERGE(v);
        } else if(v[0] == "PRINT") {
            answer.emplace_back(PRINT(v));
        }
    }
    
    return answer;
}