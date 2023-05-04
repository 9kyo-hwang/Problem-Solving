#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial) {
    istringstream ss(binomial); string buffer;
    ss >> buffer; int a = stoi(buffer);
    ss >> buffer; string op = buffer;
    ss >> buffer; int b = stoi(buffer);
    
    if(op == "+")
        return a + b;
    if(op == "-")
        return a - b;
    if(op == "*")
        return a * b;
}