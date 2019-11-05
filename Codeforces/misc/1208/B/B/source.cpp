#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
	long long n;
	long long arr[2001];
	long long narr[2001];
	long long cnt[2001] = { 0, }, curcnt[2001] = { 0, };
	bool two[2001] = { 0, };
	bool one = true;
	long long er = 0;
	long long tot = 0;
	long long i, j;
	map<long long, long long> list;
	map<long long, long long>::iterator it, ret, ret2;
	long long lmin = 1999;

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);

		ret = list.find(arr[i]);

		if (ret == list.end())
		{
			list[arr[i]] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->second != 1)
		{
			tot++;

			one = false;
		}
	}

	if (one)
	{
		printf("0\n");

		return 0;
	}

	ret2 = list.begin();

	for (i = 0; i < n; i++)
	{
		ret = list.find(arr[i]);

		narr[i] = distance(ret2, ret);

		if (ret->second != 1)
		{
			two[narr[i]] = true;

			cnt[narr[i]]++;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (!(i % 2))
		{
			for (j = i; j < n; j++)
			{
				if (two[narr[j]])
				{
					if (++curcnt[narr[j]] == cnt[narr[j]] - 1)
					{
						er++;
					}
				}

				if (er == tot)
				{
					if (j - i + 1 < lmin)
					{
						lmin = j - i + 1;
					}
				}
			}
		}

		else
		{
			if (two[narr[i - 1]])
			{
				if (curcnt[narr[i - 1]]-- == cnt[narr[i - 1]] - 1)
				{
					er--;
				}
			}

			if (er == tot)
			{
				if (n - i < lmin)
				{
					lmin = n - i;
				}
			}

			for (j = n - 1; j > i; j--)
			{
				if (two[narr[j]])
				{
					if (curcnt[narr[j]]-- == cnt[narr[j]] - 1)
					{
						er--;
					}
				}

				if (er == tot)
				{
					if (j - i < lmin)
					{
						lmin = j - i;
					}
				}
			}

			if (two[narr[i]])
			{
				curcnt[narr[i]] = 0;
			}

			er = 0;
		}
	}

	printf("%lld\n", lmin);

	return 0;
}