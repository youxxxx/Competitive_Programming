#include<cstdio>

using namespace std;

int main()
{
	int n;
	char a[100001], b[100001];
	long long int a0b0 = 0, a1b0 = 0, a0 = 0, a1 = 0;

	int i;

	scanf("%d", &n);

	scanf("%s %s", a, b);

	for (i = 0; i < n; i++)
	{
		if (a[i] == '0')
		{
			a0++;

			if (b[i] == '0')
			{
				a0b0++;
			}
		}

		else
		{
			a1++;

			if (b[i] == '0')
			{
				a1b0++;
			}
		}
	}

	printf("%I64d", a0b0*a1 + a1b0*a0 - a0b0*a1b0);

	return 0;
}