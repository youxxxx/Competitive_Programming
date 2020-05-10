#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[101];
		string str;

		scanf("%d", &n);

		scanf("%s", input);
		str = input;

		int start = -1;
		int lmax = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'A')
			{
				start = i;
			}

			if (start != -1 && str[i] == 'P')
			{
				if (i - start > lmax)
				{
					lmax = i - start;
				}
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}