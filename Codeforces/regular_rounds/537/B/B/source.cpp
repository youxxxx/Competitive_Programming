#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	long long n, k, m;
	double max = 0.0, cand;
	long long input;
	vector<long long> arr;
	vector<long long> add;
	long long i, j;
	long long left;
	long long diff;
	long long ptr = 0;
	long long sum = 0;

	scanf("%I64d %I64d %I64d", &n, &k, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		add.push_back(0);

		sum += input;
	}

	sort(arr.begin(), arr.end());

	left = m;

	for (i = n - 1; i >= 0; i--)
	{
		diff = !!(left / k)*k + !(left / k)*(left%k);
		left -= diff;
		add[i] += diff;

		sum += diff;

		if (left == 0)
		{
			break;
		}
	}

	ptr = i;

	if (ptr == -1)
	{
		ptr = 0;
	}

	max = (double)sum / (double)n;

	for (i = 0; i < n - 1 && i < m; i++)
	{
		if (left > 0)
		{
			left--;
		}

		else
		{
			if (ptr < n && add[ptr] == 0)
			{
				ptr++;
			}

			if (ptr < n)
			{
				add[ptr]--;

				if (i <= ptr)
				{
					sum--;
				}
			}
		}

		sum -= arr[i] + add[i];

		cand = (double)sum / (double)(n - i - 1);

		if (cand > max)
		{
			max = cand;
		}
	}

	printf("%.10f\n", max);

	return 0;
}