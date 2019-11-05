#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	int arr[200001] = { 0, };
	int acc[200001];
	int i;
	int input;
	int lmin = 99999999;
	int lb, ub;
	int base;
	int mul, cand, need, add;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (++arr[input] == m)
		{
			printf("0\n");

			return 0;
		}
	}

	acc[0] = 0;

	for (i = 1; i <= 200000; i++)
	{
		acc[i] = acc[i - 1] + arr[i];
	}

	for (i = 1; i <= 200000; i++)
	{
		need = m - arr[i];

		lb = i * 2;
		ub = i * 2 + 1;

		cand = 0;
		mul = 1;

		while (lb <= 200000)
		{
			add = acc[ub<200000?ub:200000] - acc[lb - 1];

			add = add < need ? add : need;
			
			need -= add;

			cand += mul*add;
			
			lb *= 2;
			ub = ub * 2 + 1;

			mul++;
		}

		if (!need&&cand < lmin)
		{
			lmin = cand;
		}
	}

	printf("%d\n", lmin);

	return 0;
}