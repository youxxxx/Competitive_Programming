#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

int main()
{
	int n;
	int input;
	int i;
	int next = 0;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		if (input > next)
		{
			next = input;
		}

		if (i >= next)
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}