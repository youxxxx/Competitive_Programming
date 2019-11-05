#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long pw[32];
	long long n;
	long long i, j, k;
	long long base, val = 1;
	long long input;
	vector<long long> bin[3];
	vector<long long> arr;
	bool all[2];
	bool reverse;
	bool three = false;
	int cnt1 = 0;
	int cnt2;

	for (i = 0; i < 32; i++)
	{
		pw[i] = val;

		val *= 2;
	}

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	if (n == 3)
	{
		for (i = 0; i < 32; i++)
		{
			bin[0].clear();
			bin[1].clear();

			for (j = 0; j < arr.size(); j++)
			{
				val = arr[j] & pw[i];
				val = !!val;

				bin[val].push_back(arr[j]);
			}

			if (bin[1].size() == 1 || bin[1].size() == 3)
			{
				printf("No\n");

				return 0;
			}
		}

		printf("Yes\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i])
		{
			break;
		}
	}

	if (i == n)
	{
		printf("Yes\n");

		return 0;
	}

	if (n % 3)
	{
		printf("No\n");

		return 0;
	}

	for (i = 0; i < 32; i++)
	{
		bin[0].clear();
		bin[1].clear();

		for (j = 0; j < arr.size(); j++)
		{
			val = arr[j] & pw[i];
			val = !!val;

			bin[val].push_back(arr[j]);
		}

		if (bin[0].size() != n&&bin[0].size() != n / 3)
		{
			printf("No\n");

			return 0;
		}

		if (bin[0].size() == n / 3)
		{
			break;
		}
	}

	if (i >= 31)
	{
		printf("Yes\n");

		return 0;
	}

	base = i;

	for (i = base + 1; i < 32; i++)
	{
		cnt1 = 0;

		all[0] = true;
		all[1] = true;
		reverse = false;

		for (j = 0; j < bin[0].size(); j++)
		{
			val = bin[0][j] & pw[i];

			val = !!val;

			all[!val] = false;

			/*
			if (val)
			{
				printf("No\n");

				return 0;
			}
			*/
		}

		if (!all[0] && !all[1])
		{
			printf("No\n");

			return 0;
		}

		cnt1 += all[1];

		if (three)
		{
			for (k = 1; k <= 2; k++)
			{
				all[0] = true;
				all[1] = true;

				for (j = 0; j < bin[k].size(); j++)
				{
					val = bin[k][j] & pw[i];

					val = !!val;

					all[!val] = false;
				}

				if (!all[0] && !all[1])
				{
					printf("No\n");

					return 0;
				}

				cnt1 += all[1];
			}

			if (cnt1 == 1 || cnt1 == 3)
			{
				printf("No\n");

				return 0;
			}
		}

		else
		{
			all[0] = true;
			all[1] = true;

			cnt2 = 0;

			for (j = 0; j < bin[1].size(); j++)
			{
				val = bin[1][j] & pw[i];

				val = !!val;

				cnt2 += val;

				all[!val] = false;
			}

			if (all[0] && cnt1 || all[1] && cnt1)
			{
				printf("No\n");

				return 0;
			}

			if (!all[0] && !all[1])
			{
				if (!cnt1 || cnt2 != n / 3)
				{
					printf("No\n");

					return 0;
				}

				for (j = bin[1].size() - 1; j >= 0; j--)
				{
					val = bin[1][j] & pw[i];

					if (val)
					{
						bin[2].push_back(bin[1][j]);

						bin[1].erase(bin[1].begin() + j);
					}
				}

				three = true;
			}
		}

		/*
		if (reverse&&all[1])
		{
			printf("No\n");

			return 0;
		}
		*/
	}

	printf("Yes\n");

	return 0;
}