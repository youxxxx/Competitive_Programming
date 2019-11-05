#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	vector<long long> mxword;
	long long arrsize;
	long long max = 1;
	long long presize = 0;
	long long input;
	long long i, j, k;

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arrsize = mxword.size();

		if (input > presize)
		{
			for (j = 0; j < input - presize && j < arrsize; j++)
			{
				mxword[j] = 0;
			}

			for (j = 0; j < input - arrsize; j++)
			{
				mxword.push_back(0);
			}
		}

		else
		{
			for (j = 0; j < input; j++)
			{
				if (mxword[j] != max - 1)
				{
					break;
				}
			}

			if (j == input)
			{
				mxword[input - 1] = max++;
			}

			else
			{
				for (k = input - 1; k >= 0; k--)
				{
					if (mxword[k] < max - 1)
					{
						mxword[k]++;

						break;
					}

					mxword[k] = 0;
				}
			}
		}

		presize = input;
	}

	printf("%lld\n", max);

	return 0;
}