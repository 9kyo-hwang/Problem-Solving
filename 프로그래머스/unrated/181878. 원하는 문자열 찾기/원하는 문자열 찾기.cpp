#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    // 모두 소문자로 변환하여 대소문자 구분 없이 비교
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);

    int len1 = myString.length();
    int len2 = pat.length();
    int match = 0;

    // myString을 순회하며 pat과 일치하는 부분 문자열이 있는지 확인
    for (int i = 0; i <= len1 - len2; i++) {
        bool found = true;
        for (int j = 0; j < len2; j++) {
            if (myString[i+j] != pat[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            match = 1;
            break;
        }
    }

    return match;
}