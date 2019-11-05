#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, m, k;
	vector<long long> arr;
	long long input;
	long long i;
	long long q = 1, r = 0;

	scanf("%I64d %I64d %I64d", &n, &m, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] > k)
		{
			break;
		}

		if (r + arr[i] > k)
		{
			if (q == m)
			{
				break;
			}

			q++;

			r = arr[i];
		}
		/*
		else if (r + arr[i] == k)
		{
			q++;

			if (q == m)
			{
				i--;

				break;
			}
		}
		*/
		else
		{
			r += arr[i];
		}
	}

	printf("%I64d", n - 1 - i);

	return 0;
}