#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class Table {
public:
    Table() {
        parents.resize(R * C);
        iota(parents.begin(), parents.end(), 0);

        data.assign(R * C, "EMPTY");
    }
    ~Table() = default;
    
    void update(const vector<string>& command) {
        if(command.size() == 3) {
            int r = stoi(command[0]), c = stoi(command[1]);
            string value = command[2];
            
            data[find(convert(r, c))] = value;
        } else if(command.size() == 2) {
            string value1 = command[0], value2 = command[1];
            
            for(string &content : data) {
                if(content == value1) {
                    content = value2;
                }
            }
        }
    }
    
    void merge(const vector<string>& command) {
        int r1 = stoi(command[0]), c1 = stoi(command[1]);
        int r2 = stoi(command[2]), c2 = stoi(command[3]);
        
        unite(convert(r1, c1), convert(r2, c2));
    }
    
    void unmerge(const vector<string>& command) {
        int r = stoi(command[0]), c = stoi(command[1]);
        
        int parent = find(convert(r, c));
        string content = data[parent];

        for(int i = 0; i < R * C; ++i) {
            if(parents[i] == parent) {
                parents[i] = i;
                data[i] = "EMPTY";
            }
        }

        data[convert(r, c)] = content;
    }
    
    string print(const vector<string>& command) {
        int r = stoi(command[0]), c = stoi(command[1]);
        
        return data[find(convert(r, c))];
    }

private:
    static const int R = 51, C = 51;
    vector<string> data;
    vector<int> parents;

    inline int convert(int r, int c) {
        return r * C + c;
    }

    inline int find(int x) {
        while(x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return parents[x];
    }

    inline void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y) {
            return;
        }

        if(data[x] == "EMPTY") {
            for(int& parent : parents) {
                if(parent == x) {
                    parent = y;
                }
            }
        } else {
            for(int& parent : parents) {
                if(parent == y) {
                    parent = x;
                }
            }
        }
    }
};

pair<string, vector<string>> command_parser(const string& command) {
    istringstream ss(command);
    string cmd; ss >> cmd;

    string buffer;
    vector<string> v;
    while(ss >> buffer) {
        v.emplace_back(buffer);
    }

    return {cmd, v};
}

vector<string> solution(vector<string> commands) {
    Table table;
    vector<string> answer;

    for(const string& command : commands) {
        const auto& [cmd, v] = command_parser(command);
        
        if(cmd == "UPDATE") {
            table.update(v);
        } else if(cmd == "MERGE") {
            table.merge(v);
        } else if(cmd == "UNMERGE") {
            table.unmerge(v);
        } else if(cmd == "PRINT") {
            answer.emplace_back(table.print(v));
        }
    }

    return answer;
}