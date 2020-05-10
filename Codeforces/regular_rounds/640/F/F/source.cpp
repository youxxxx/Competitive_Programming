#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b, c;
		string sol;

		scanf("%d %d %d", &a, &b, &c);

		if (!a && !b)
		{
			for (int i = 0; i <= c; i++)
			{
				sol.push_back('1');
			}
		}

		else if (!b && !c)
		{
			for (int i = 0; i <= a; i++)
			{
				sol.push_back('0');
			}
		}

		else
		{
			for (int i = 0; i <= a; i++)
			{
				sol.push_back('0');
			}

			for (int i = 0; i < b - !(b % 2); i++)
			{
				sol.push_back('0' + !(i % 2));
			}

			for (int i = 0; i < c; i++)
			{
				sol.push_back('1');
			}

			if (!(b % 2))
			{
				sol.push_back('0');
			}
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}