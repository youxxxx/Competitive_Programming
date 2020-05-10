#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n, k;
	long long input;
	vector<long long> arr;
	long long i, j;
	long long cnt;
	long long bit = 1, add;
	long long x = 0, x2 = 0;
	long long cand = 0, cand2 = 0;
	long long max;
	bool small = false;

	scanf("%lld %lld", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	max = (long long)(log2((double)k));
	bit = (long long)pow(2.0, max);

	cnt = 0;

	for (j = 0; j < n; j++)
	{
		cnt += !!(bit&arr[j]);
	}

	if (cnt >= n / 2)
	{
		add = 0;

		cand += bit*(cnt - n / 2);
	}

	else
	{
		add = bit;

		cand += bit*cnt;
	}

	x += add;

	bit >>= 1;

	while(bit)
	{
		if (x + bit > k)
		{
			cnt = 0;

			for (j = 0; j < n; j++)
			{
				cnt += !!(bit&arr[j]);
			}

			if (cnt >= n / 2)
			{
				add = 0;

				cand2 += bit*(cnt - n / 2);
			}

			else
			{
				add = bit;

				cand2 += bit*cnt;
			}

			x += add;

			x2 += add;
		}

		else
		{
			small = true;

			cnt = 0;

			for (j = 0; j < n; j++)
			{
				cnt += !!(bit&arr[j]);
			}

			if (cnt < n / 2)
			{
				add = 0;

				cand += bit*(cnt - n / 2);

				cand2 += bit*(cnt - n / 2);
			}

			else
			{
				add = bit;

				cand += bit*cnt;

				cand2 += bit*cnt;
			}

			x2 += add;
		}

		bit >>= 1;
	}

	for (i = 0; i < n; i++)
	{

	}

	return 0;
}