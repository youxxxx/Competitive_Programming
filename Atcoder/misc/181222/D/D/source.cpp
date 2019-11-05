#include<cstdio>
#include<vector>

int main()
{
	int n;
	long long input;
	int i;
	bool odd = false;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		if (!odd&&input%2)
		{
			odd = true;
		}
	}

	if (odd)
	{
		printf("first\n");
	}

	else
	{
		printf("second\n");
	}

	return 0;
}