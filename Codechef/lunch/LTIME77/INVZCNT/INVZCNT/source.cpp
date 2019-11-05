#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	vector<long long> arr;
	int most, cur;
	int k, p;
	int input;
	int i;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d %d", &n, &k, &p);

		arr.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		if (p == 0)
		{
			most = 0;

			if (k % 2)
			{
				for (i = 0; i < n; i++)
				{
					if (arr[i] > most)
					{
						most = arr[i];
					}
				}
			}

			else
			{
				for (i = 0; i < n; i++)
				{
					cur = 0;

					/*
					if (arr[i] > most)
					{
					cur = arr[i - 1];
					}
					*/

					if (i == n - 1)
					{
						if (arr[i - 1] > most)
						{
							cur = arr[i - 1];
						}
					}

					else if (i == 0)
					{
						if (arr[i + 1] > most)
						{
							cur = arr[i + 1];
						}
					}

					else
					{
						cur = arr[i - 1] < arr[i + 1] ? arr[i - 1] : arr[i + 1];
					}

					if (cur > most)
					{
						most = cur;
					}
				}
			}
		}

		else
		{
			most = 1000000001;

			if (k % 2)
			{
				for (i = 0; i < n; i++)
				{
					if (arr[i] < most)
					{
						most = arr[i];
					}
				}
			}

			else
			{
				for (i = 0; i < n; i++)
				{
					cur = 1000000001;

					/*
					if (arr[i] < most)
					{
					cur = arr[i - 1];
					}
					*/

					if (i == n - 1)
					{
						if (arr[i - 1] < most)
						{
							cur = arr[i - 1];
						}
					}

					else if (i == 0)
					{
						if (arr[i + 1] < most)
						{
							cur = arr[i + 1];
						}
					}

					else
					{
						cur = arr[i - 1] > arr[i + 1] ? arr[i - 1] : arr[i + 1];
					}

					if (cur < most)
					{
						most = cur;
					}
				}
			}
		}

		printf("%d\n", most);
	}

	return 0;
}