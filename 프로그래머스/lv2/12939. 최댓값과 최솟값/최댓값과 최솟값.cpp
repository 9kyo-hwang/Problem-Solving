#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    istringstream ss(s);
    string buffer;
    vector<int> v;
    while(ss >> buffer)
        v.emplace_back(stoi(buffer));

    sort(v.begin(), v.end());
    
    return to_string(v[0]) + " " + to_string(v[v.size() - 1]);
}