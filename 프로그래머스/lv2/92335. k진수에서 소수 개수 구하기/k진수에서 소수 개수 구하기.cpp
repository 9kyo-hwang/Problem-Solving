#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;
using ll = long long;

int solution(int n, int k) {
	string str;
	while (n)
	{
		str += to_string(n % k);
		n /= k;
	}

	reverse(str.begin(), str.end());
	istringstream ss(str);
	string buffer;

	int answer = 0;
	while (getline(ss, buffer, '0'))
	{
        if (buffer.empty()) continue;
        
		ll num = stol(buffer);
        if(num < 2) continue;
        
		bool prime = false;
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				prime = true;
				break;
			}
		}

		if (!prime) answer++;
	}
    return answer;
}