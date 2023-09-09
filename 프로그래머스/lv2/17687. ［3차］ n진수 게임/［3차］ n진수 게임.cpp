#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    const string digits = "0123456789ABCDEF";
    string numbers = "0"; // default
	for (int i = 1; i < t * m; i++)
	{
        int num = i;
		string str = "";
		while (num)
		{
			str += digits[num % n];
            num /= n;
		}
		reverse(str.begin(), str.end());
		numbers += str;
	}

	string answer = "";
	for (int i = (p - 1); i < t * m; i += m)
		answer += numbers[i];
	return answer;
}