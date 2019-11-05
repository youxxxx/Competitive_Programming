#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	vector<long long> arr;
	long long input;
	long long *res;
	long long pre;

	scanf("%d", &n);

	n /= 2;

	res = new long long[n * 2];

	scanf("%I64d", &input);

	res[0] = 0;
	res[n * 2 - 1] = input;

	for (i = 1; i < n; i++)
	{
		scanf("%I64d", &input);

		pre = res[n * 2 - i] + res[i - 1];

		if (input >= pre)
		{
			res[n * 2 - i - 1] = res[n * 2 - i];

			res[i] = (input - res[n * 2 - i]);
		}

		else
		{
			res[i] = res[i - 1];

			res[n * 2 - 1 - i] = input - res[i - 1];
		}

		/*
		if (input >= res[n * 2 - i])
		{
			res[n * 2 - i - 1] = res[n * 2 - i];

			res[i] = (input - res[n * 2 - i]);
		}

		else
		{
			res[i] = res[i - 1];

			res[n * 2 - 1 - i] = input - res[i - 1];
		}
		*/
	}

	for (i = 0; i < n * 2; i++)
	{
		printf("%I64d ", res[i]);
	}

	return 0;
}