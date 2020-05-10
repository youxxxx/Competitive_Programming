#include<cstdio>
#include<set>
#include<map>

using namespace std;

int main()
{
	int t, z;
	int *arr, *psum;
	int i, j;
	int input;
	int n;
	int cnt;
	set<int> nums;
	//set<int> cur[2];
	set<int>::iterator it;
	map<int, int> rev;
	map<int, int>::iterator it2, ret;
	int sum, total;
	int off;
	int temp;
	int part1, part2, partc;

	arr = new int[1000001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 1; i <= 1000000; i++)
		{
			arr[i] = 0;

			psum[i] = 0;
		}

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &input);

			arr[input]++;

			nums.insert(input);
		}

		psum[1] = arr[1];

		for (i = 2; i <= 1000000; i++)
		{
			psum[i] = psum[i - 1] + arr[i];
		}

		for (i = 1; i <= 1000000; i++)
		{
			if (arr[i])
			{
				ret = rev.find(arr[i]);

				if (ret == rev.end())
				{
					rev[arr[i]] = 1;
				}

				else
				{
					ret->second++;
				}
			}
		}

		sum = 0;

		cnt = 0;
		
		for (it2 = rev.begin(); it2 != rev.end(); it2++)
		{
			total += it2->second;
		}

		for (it = nums.begin(); it != nums.end(); it++)
		{
			while (it2!=rev.end() && it2->second < *it)
			{
				sum += it2->second;

				it2++;
			}

			part1 = psum[arr[*it]] + (total - sum);
			part2 = (total - psum[arr[*it]]) + sum;

			cnt += psum[arr[*it]];
		}

		/*
		cnt = 0;

		cur[0] = nums;

		off = 0;

		for (it = nums.begin(); it != nums.end(); it++)
		{
			for (it2 = cur[off].begin(); it2 != cur[off].end(); it2++)
			{
				if (arr[*it] >= *it2&&arr[*it2] >= *it)
				{
					 cnt++;
				}

				if (arr[*it2] > *it)
				{
					cur[!off].insert(*it2);
				}
			}

			off = !off;
		}
		*/

		/*
		for (i = 1; i <= 100000; i++)
		{
			if (arr[i] > 0)
			{
				for (j = 1; j <= 100000; j++)
				{
					if (arr[i] >= j&&arr[j] >= i)
					{
						cnt++;
					}
				}
			}
		}
		*/

		printf("%d\n", cnt);

		nums.clear();
		//cur[0].clear();
		//cur[1].clear();
	}

	return 0;
}