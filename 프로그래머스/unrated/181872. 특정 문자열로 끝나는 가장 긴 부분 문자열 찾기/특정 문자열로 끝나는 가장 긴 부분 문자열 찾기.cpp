#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString, string pat) {
    return myString.substr(0, myString.rfind(pat) + pat.length());
}