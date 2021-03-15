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
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int lacc[300001];
		int racc[300001];

		char input[300001];

		scanf("%s", input);
		const string str = input;

		lacc[0] = 0;
		lacc[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			if (str[i - 2] == str[i - 1])
			{
				lacc[i] = 1;
			}

			else
			{
				lacc[i] = lacc[i - 1] + 1;
			}
		}

		racc[n] = 0;
		racc[n - 1] = 1;

		for (int i = n - 2; i >= 0; i--)
		{
			if (str[i + 1] == str[i])
			{
				racc[i] = 1;
			}

			else
			{
				racc[i] = racc[i + 1] + 1;
			}
		}
		
		for (int i = 0; i <= n; i++)
		{
			int sol = 1;

			if (i > 0 && str[i - 1] == 'L')
			{
				sol += lacc[i];
			}

			if (i < n && str[i] == 'R')
			{
				sol += racc[i];
			}

			printf("%d ", sol);
		}

		printf("\n");
	}

	return 0;
}