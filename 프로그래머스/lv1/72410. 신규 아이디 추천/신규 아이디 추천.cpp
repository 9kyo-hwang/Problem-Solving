#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); // 1: 소문자로 치환
    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), ""); // 2: -, _, . 제외 모두 제거
    new_id = regex_replace(new_id, regex("[.]{2,}"), "."); // 3: 2번 이상 연속된 .을 .으로 변환
    new_id = regex_replace(new_id, regex("^\\.|\\.$"), ""); // 4: 문장 앞 뒤 마침표 제거
    if(new_id.empty()) new_id = "a"; // 5: 빈 문자열이면 a 대입
    if(new_id.length() >= 16) { // 6: 길이가 16자 이상이면
        new_id = new_id.substr(0, 15); // 15개만 남김
        new_id = regex_replace(new_id, regex("\\.$"), ""); // 제거 후 끝 . 제거
    }
    while(new_id.length() <= 2) new_id += new_id.back(); // 7: 길이가 2자 이하면 마지막 문자를 길이가 3이 될 때까지 반복해서 붙임
    
    return new_id;
}