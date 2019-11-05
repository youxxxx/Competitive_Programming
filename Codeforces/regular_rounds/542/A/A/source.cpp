#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int pos = 0, neg = 0;
	int input;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		pos += (input > 0);
		neg += (input < 0);
	}

	if (pos >= n / 2 + n % 2)
	{
		printf("1\n");
	}

	else if (neg >= n / 2 + n % 2)
	{
		printf("-1\n");
	}

	else
	{
		printf("0\n");
	}

	return 0;
}