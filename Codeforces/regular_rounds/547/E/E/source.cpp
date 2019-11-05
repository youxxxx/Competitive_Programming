#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	long long h;
	int n, i;
	long long cur = 0, lmin = 0;
	long long input;
	vector<long long> arr;
	long long cnt = 0;
	long long q;

	scanf("%I64d %d",&h, &n);

	cur = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		cur += input;

		if (h + cur <= 0)
		{
			printf("%d\n", i + 1);

			return 0;
		}

		if (cur < lmin)
		{
			lmin = cur;
		}
	}

	if (cur >= 0)
	{
		printf("-1\n");

		return 0;
	}

	h += lmin;

	q = h / -cur;

	cnt += q*n;
	h -= q*-cur;
	h -= lmin;

	for (i = 0; i < n; i++)
	{
		h += arr[i];

		if (h <= 0)
		{
			printf("%I64d\n", cnt + i + 1);

			return 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		h += arr[i];

		if (h <= 0)
		{
			printf("%I64d\n", cnt + n + i + 1);

			return 0;
		}
	}

	return 0;
}