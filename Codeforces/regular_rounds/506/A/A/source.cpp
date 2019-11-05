#include<cstdio>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

int main()
{
	char t[51];
	int n, k;
	int i, j;
	int lb = 0, ub = 0;
	int lf, uf = 0;
	
	scanf("%d %d %s", &n, &k, t);

	while (lb + ub < n)
	{
		ub = 0;

		while (lb<n && t[++lb] != t[0]);

		while (lb + ++ub < n&&t[ub + lb] == t[ub]);
	}

	/*
	lf = n;

	while (lf - uf >= 0)
	{
		uf = 0;

		while (--lf >= 0 && t[lf] != t[n - 1]);

		while (lf - ++uf >= 0 &&t[lf - uf] == t[n - uf - 1]);
	}
	*/

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < lb; j++)
		{
			printf("%c", t[j]);
		}
	}

	for (i = lb; i < n; i++)
	{
		printf("%c", t[i]);
	}

	return 0;
}