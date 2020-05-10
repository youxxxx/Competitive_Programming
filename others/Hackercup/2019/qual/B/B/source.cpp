#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n;
	int i;
	char input[10000];
	string str;
	int cnt;

	freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		cnt = 0;

		for (i = 1; i < n; i++)
		{
			if (str[i] == 'B')
			{
				cnt++;
			}
		}

		if (cnt == n - 1 || (n > 3 && cnt < 2) || (n <= 3 && cnt == 0))
		{
			printf("Case #%d: N\n", z + 1);
		}

		else
		{
			printf("Case #%d: Y\n", z + 1);
		}
	}

	return 0;
}