#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		char input[101];
		string str;
		int n;

		scanf("%s", input);
		str = input;
		n = str.size();

		string sol;
		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			int val;

			val = str[i] - '0';

			if (val > cur)
			{
				for (int j = 0; j < abs(val - cur); j++)
				{
					sol.push_back('(');
				}
			}

			else if (val < cur)
			{
				for (int j = 0; j < abs(val - cur); j++)
				{
					sol.push_back(')');
				}
			}

			sol.push_back(str[i]);

			cur = val;
		}

		for (int i = 0; i < cur; i++)
		{
			sol.push_back(')');
		}

		printf("Case #%d: %s\n", tc, sol.c_str());
	}

	return 0;
}