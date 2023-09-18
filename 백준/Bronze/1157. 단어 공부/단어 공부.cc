#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string str;
    cin >> str;

    vector<int> alphabet(26, 0);

    for(auto i : str) {
        if('A' <= i && i <= 'Z')
            alphabet[i - 'A']++;
        else if('a' <= i && i <= 'z')
            alphabet[i - 'a']++;
    }

    int idx = 0, max = 0, count = 0;
    for(auto i = 0; i < alphabet.size(); i++) {
        if(alphabet[i] > max) {
            max = alphabet[i];
            idx = i;
            count = 1;
        }
        else if(alphabet[i] == max)
            count++;
    }

    if(count >= 2) cout << "?";
    else cout << char(idx + 'A');

    return 0;
}