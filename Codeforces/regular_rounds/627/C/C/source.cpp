#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>
#include<map>
#include<set>
#include<stack>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[200001];
		string str;

		scanf("%s", input);

		str = input;
		n = str.size();

		int lmax = 0;
		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'L')
			{
				cur++;
			}

			else
			{
				if (cur > lmax)
				{
					lmax = cur;
				}

				cur = 0;
			}
		}

		if (cur > lmax)
		{
			lmax = cur;
		}

		printf("%d\n", lmax + 1);
	}

	return 0;
}`