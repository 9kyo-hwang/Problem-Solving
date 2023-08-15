#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	bool set[21]; memset(set, false, 21);

	char cmd[10]; int num;
	int M; cin >> M;

	while(M--)
	{
		cin >> cmd;
		if(cmd[0] == 'a')
		{
			if (cmd[1] == 'd')
			{
				cin >> num;
				set[num] = true;
			}
			else memset(set, true, 21);
		}
		else if(cmd[0] == 'r')
		{
			cin >> num;
			set[num] = false;
		}
		else if(cmd[0] == 'c')
		{
			cin >> num;
			cout << set[num] << '\n';
		}
		else if(cmd[0] == 't')
		{
			cin >> num;
			set[num] = !set[num];
		}
		else if(cmd[0] == 'e')
		{
			memset(set, false, 21);
		}
	}

	return 0;
}