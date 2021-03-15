#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[51];

		scanf("%s", input);
		const string s = input;
		const int n = s.size();

		bool found = false;

		for (int i = 0; i < 8; i++)
		{
			int temp = i;

			int val[3];

			for (int j = 0; j < 3; j++)
			{
				val[j] = temp % 2 * 2 - 1;

				temp /= 2;
			}

			bool valid = true;

			{
				int cur = 0;

				for (int j = 0; j < n; j++)
				{
					cur += val[s[j] - 'A'];

					if (cur < 0)
					{
						valid = false;

						break;
					}
				}

				if (cur)
				{
					valid = false;
				}
			}

			if (valid)
			{
				found = true;

				break;
			}
		}
		
		if (found)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}