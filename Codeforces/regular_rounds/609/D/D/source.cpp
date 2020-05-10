#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;

	scanf("%d", &n);

	long long sol = 0;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	long long left = 0;
	bool fixed, bottom;

	for (int i = 0; i < n; i++)
	{
		if (!left)
		{
			left = arr[i] % 2;

			sol += arr[i] / 2 + (left * (i < n - 1));

			if (left && i < n - 1)
			{
				if (arr[i + 1] < arr[i] && !((arr[i] - arr[i + 1]) % 2))
				{
					fixed = true;

					bottom = true;
				}

				else
				{
					fixed = false;

					bottom = false;
				}
			}
		}

		else
		{
			left = (arr[i] - 1) % 2;

			sol += (arr[i] - 1) / 2;

			if (left)
			{
				if ((i == n - 2) || (fixed && bottom && arr[i] < arr[i - 1] && !((arr[i - 1] - arr[i]) % 2)))
				{
					left = 0;
				}

				else
				{
					sol++;

					if (fixed)
					{
						bottom = !bottom;
					}

					else if (arr[i + 1] < arr[i] && !((arr[i]-arr[i+1]) % 2))
					{
						fixed = true;

						bottom = true;
					}
				}
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}