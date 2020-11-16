#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	long long a, b, c, d;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	long long sol = 0;

	for (long long i = a + b > c ? a + b : c; i <= b + c; i++)
	{
		long long left = -1, right = -1, up = -1, down = -1;
		long long cnt = 0;

		if (i - a >= b&&i - a <= c)
		{
			left = i - a;

			cnt++;
		}

		if (i - b >= b&&i - b <= c)
		{
			right = i - b;

			cnt++;
		}

		if (i - b >= a&&i - b <= b)
		{
			down = i - b;

			cnt++;
		}

		if (i - c >= a&&i - c <= b)
		{
			up = i - c;

			cnt++;
		}

		if (cnt < 2)
		{
			continue;
		}

		long long base = 0;

		if (left != -1 && right != -1)
		{
			base = b - a;
		}

		else if (up != -1 && down != -1)
		{
			base = c - b;
		}

		else if (left != -1 && down != -1)
		{
			base = left - b;
		}

		else if (right != -1 && up != -1)
		{
			base = c - right;
		}

		long long mult = i - 1 < d ? i - 1 : d;

		sol += (base + 1)*(mult - c + 1);
	}

	printf("%lld\n", sol);

	return 0;
}