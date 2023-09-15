#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string str; cin >> str;
    sort(str.begin(), str.end(), greater<>());
    cout << str;
    
    return 0;
}