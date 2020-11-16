#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	int val[10001] = { 0, };
	int ub = n - 1;
	int ptr = 1;

	for (int i = 2; i <= n; i++)
	{
		printf("? %d %d\n", i, ptr);
		fflush(stdout);
		scanf("%d", &val[i]);
		printf("? %d %d\n", ptr, i);
		fflush(stdout);
		scanf("%d", &val[ptr]);

		if (val[i] > val[ptr])
		{
			val[ptr] = 0;
		}

		else
		{
			val[i] = 0;
			ptr = i;
		}
	}

	printf("!");

	for (int i = 1; i <= n; i++)
	{
		if (!val[i])
		{
			printf(" %d", n);
		}

		else
		{
			printf(" %d", val[i]);
		}
	}

	printf("\n");

	return 0;
}