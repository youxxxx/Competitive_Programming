#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> perf, arr, temp, num, acc;
	int t, z;
	int i, j;
	int n, q;
	int l, r;
	int input;

	i = 0;
	while ((++i*i) <= 2000000)
	{
		perf.push_back(i*i);
	}

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);

			num.push_back(-1);

			acc.push_back(0);
		}

		temp.push_back(0);

		for (i = 1; i < n; i++)
		{
			for (j = temp.size() - 1; j >= 0; j--)
			{
				if (binary_search(perf.begin(), perf.end(), arr[temp[j]] + arr[i]))
				{
					num[temp[j]] = i;

					temp.erase(temp.begin() + j);
				}
			}

			temp.push_back(i);
		}

		temp.clear();

		for (i = 0; i < n; i++)
		{
			if (num[i] != -1)
			{
				acc[num[i]]++;
			}
		}

		for (i = 1; i < n; i++)
		{
			acc[i] = acc[i] + acc[i - 1];
		}

		scanf("%d", &q);

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &l, &r);

			if (l == r)		
			{
				printf("1\n");
			}

			else
			{
				printf("%d\n", r - acc[r] - acc[l] +1);
			}
		}

		arr.clear();
		num.clear();
	}

	return 0;
}