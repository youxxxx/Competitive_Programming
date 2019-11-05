#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	long long n, k;
	long long cur, temp;
	long long cnt, ptr;
	long long i, j;
	long long bits[32];
	long long mptr;

	scanf("%I64d %I64d", &n, &k);

	if (n == 1 && k == 1)
	{
		printf("YES\n1\n");

		return 0;
	}

	cur = 1;
	ptr = 0;
	cnt = 0;

	temp = n;

	while (temp)
	{
		bits[ptr++] = temp % 2;
		cnt += temp % 2;

		temp >>= 1;
		cur <<= 1;
	}

	if (k < cnt)
	{
		printf("NO\n");

		return 0;
	}

	for (i = ptr - 1; i >= 1; i--)
	{
		if (cnt + bits[i] >= k)
		{
			bits[i] -= k - cnt;
			bits[i - 1] += (k - cnt) * 2;

			mptr = i;

			break;
		}

		else
		{
			cnt += bits[i];
			bits[i - 1] += bits[i] * 2;
			bits[i] = 0;
		}
	}

	if (i == 0)
	{
		printf("NO\n");

		return 0;
	}

	cur = 1;

	printf("YES\n");

	for (i = 0; i <= mptr; i++)
	{
		for (j = 0; j < bits[i]; j++)
		{
			printf("%I64d ", cur);
		}

		cur <<= 1;
	}

	return 0;
}