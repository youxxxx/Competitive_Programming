#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i;
	int nmax = 0 , mmax = 0;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > nmax)
		{
			nmax = input;
		}
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		if (input > mmax)
		{
			mmax = input;
		}
	}

	printf("%d %d\n", nmax , mmax);

	return 0;
}
