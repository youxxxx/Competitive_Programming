#include<cstdio>

using namespace std;

int main()
{
	long long int n, k, s;
	long long int q, r, cur;
	int i;

	scanf("%I64d %I64d %I64d", &n, &k, &s);

	if (s<k || s>(n - 1)*k)
	{
		printf("NO");
	}

	else
	{
		q = s / k;
		r = s - q*k;

		if (q + r >= n)
		{
			q++;
			r -= k;
		}

		printf("YES\n");

		cur = 1;

		for (i = 0; i < k - 1; i++)
		{
			cur -= ((i % 2) * 2 - 1)*q;

			printf("%I64d ", cur);
		}

		cur += ((k % 2) * 2 - 1)*(q + r);

		printf("%I64d", cur);
	}

	return 0;
}