#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	char input[101];
	string str;
	int n;
	int i, j;
	int lamp[101];
	int cur[101], interv[101];
	int lmax = 0, cand;

	scanf("%d", &n);
	scanf("%s", input);
	str = input;

	for (i = 0; i < n; i++)
	{
		lamp[i] = str[i] - '0';

		lmax += lamp[i];
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &interv[i], &cur[i]);
	}

	for (i = 1; i <= 1000; i++)
	{
		cand = 0;

		for (j = 0; j < n; j++)
		{
			if (cur[j] == i)
			{
				lamp[j] = !lamp[j];

				cur[j] += interv[j];
			}

			cand += lamp[j];
		}

		if (cand > lmax)
		{
			lmax = cand;
		}
	}

	printf("%d\n", lmax);

	return 0;
}