#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	long long n, l;
	long long bits, range;
	vector<long long> arr;
	long long diff;
	long long input;
	long long i, j;
	long long lmin;

	scanf("%lld %lld", &n, &l);

	bits = (l * 8) / n;

	if (bits > 32)
	{
		bits = 32;
	}

	range = (long long)pow(2.0, bits);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	lmin = n;

	j = 0;

	diff = 0;

	for (i = 0; i < n && j < n; i++)
	{
		if (i != 0 && arr[i - 1] == arr[i])
		{
			continue;
		}

		while (j != n && diff < range)
		{
			j++;

			if (j == n)
			{
				break;
			}

			if (arr[j] != arr[j - 1])
			{
				diff++;
			}
		}

		if (n - (j - i) < lmin)
		{
			lmin = n - (j - i);
		}

		diff--;
	}

	printf("%lld\n", lmin);

	return 0;
}