#include<cstdio>
#include<set>
#include<cmath>

using namespace std;

int main()
{
	int t, z;
	int arr[10001];
	int sum[20001];
	int n;
	int i;
	int input;
	int max;
	int cand;
	int sol;
	set<int> nums, sums, temp;
	set<int>::iterator it, it2, cidx, er;
	bool outd;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		sum[0] = 1;
		sums.insert(0);

		for (i = 1; i <= 10000; i++)
		{
			arr[i] = 0;
			sum[i] = 0;
		}

		for (i = 10001; i <= 20000; i++)
		{
			sum[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			if (!arr[input])
			{
				nums.insert(input);
			}

			for (it = sums.begin(); it != sums.end(); it++)
			{
				if (sum[*it + input] == 0)
				{
					temp.insert(*it + input);
				}

				sum[*it + input]++;
			}

			for (it = temp.begin(); it != temp.end(); it++)
			{
				sums.insert(*it);
			}

			temp.clear();

			sums.insert(input);

			sum[input]++;

			arr[input]++;
		}

		sol = sums.size();

		max = 0;

		for (it = nums.begin(); it != nums.end(); it++)
		{
			cand = 0;

			for (it2 = sums.begin(); it2 != sums.end(); it2++)
			{
				if (*it2 < *it)
				{
					continue;
				}

				if (*it * 2 == *it2)
				{
					if (arr[*it] == 1)
					{
						continue;
					}
				}

				if (sum[*it2 - *it])
				{
					if (sum[*it2] >= 2)
					{
						cand++;
					}
				}
			}

			if (cand > max)
			{
				max = cand;
				
				cidx = it;
			}
		}

		sol += max + sums.size();

		if (max == 0)
		{
			printf("%d\n", sol);

			nums.clear();
			sums.clear();

			continue;
		}

		it2 = sums.end();

		outd = false;

		while (it2-- != sums.begin())
		{
			if (outd)
			{
				sums.erase(er);

				outd = false;
			}

			if (*cidx * 2 == *it2)
			{
				if (arr[*cidx] == 1)
				{
					continue;
				}
			}

			if (sum[*it2 - *cidx])
			{
				sum[*it2]--;

				if (sum[*it2] == 0)
				{
					er = it2;

					outd = true;
				}
			}
		}

		if (outd)
		{
			sums.erase(er);

			outd = false;
		}

		arr[*cidx]--;

		if (arr[*cidx] == 0)
		{
			nums.erase(cidx);
		}

		max = 0;

		for (it = nums.begin(); it != nums.end(); it++)
		{
			cand = 0;

			for (it2 = sums.begin(); it2 != sums.end(); it2++)
			{
				if (*it2 < *it)
				{
					continue;
				}

				if (*it * 2 == *it2)
				{
					if (arr[*it] == 1)
					{
						continue;
					}
				}

				if (sum[*it2 - *it])
				{
					if (sum[*it2] >= 2)
					{
						cand++;
					}
				}
			}

			if (cand > max)
			{
				max = cand;

				cidx = it;
			}
		}

		sol += max;

		if (max == 0)
		{
			printf("%d\n", sol);

			nums.clear();
			sums.clear();

			continue;
		}

		it2 = sums.end();

		outd = false;

		while (it2-- != sums.begin())
		{
			if (outd)
			{
				sums.erase(er);

				outd = false;
			}

			if (*cidx * 2 == *it2)
			{
				if (arr[*cidx] == 1)
				{
					continue;
				}
			}

			if (sum[*it2 - *cidx])
			{
				sum[*it2]--;

				if (sum[*it2] == 0)
				{
					er = it2;

					outd = true;
				}
			}
		}

		if (outd)
		{
			sums.erase(er);

			outd = false;
		}

		arr[*cidx]--;

		if (arr[*cidx] == 0)
		{
			nums.erase(cidx);
		}

		printf("%d\n", sol);

		nums.clear();
		sums.clear();
	}

	return 0;
}