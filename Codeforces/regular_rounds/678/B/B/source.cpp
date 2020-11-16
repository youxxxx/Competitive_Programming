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

int main()
{
	bool isprime[1000];

	for (int i = 1; i < 1000; i++)
	{
		isprime[i] = true;
	}

	for (int i = 2; i < 1000; i++)
	{
		if (isprime[i])
		{
			for (int j = i * 2; j < 1000; j += i)
			{
				isprime[j] = false;
			}
		}
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		int sol[101][101];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sol[i][j] = 1;
			}
		}

		int val = 1;

		for (int i = 1; i <= 1000; i++)
		{
			if (isprime[i])
			{
				continue;
			}

			val = i;
			
			if (isprime[n - 1 + i])
			{
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			sol[i][i] = val;
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", sol[i][j]);
			}

			printf("\n");
		}
	}

	return 0;
}