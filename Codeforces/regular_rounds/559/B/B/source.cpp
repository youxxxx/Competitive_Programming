#include<cstdio>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	int start;
	long long input;

	vector<long long> arr;
	long long lmin = 9999999999;
	long long extension = 9999999999;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		/*
		if (arr[i] < lmin)
		{
			lmin = arr[i];
		}

		if ((double)i*lmin < extension)
		{
			extension = (double)i*lmin;
		}

		if ((double)(n-i-1)*lmin < extension)
		{
			extension = (double)(n - i - 1)*lmin;
		}
		*/

		if (i > 0)
		{
			if (arr[i] / i < extension)
			{
				extension = arr[i] / i;
			}
		}

		if (i < n - 1)
		{
			if (arr[i] / (n - i - 1) < extension)
			{
				extension = arr[i] / (n - i - 1);
			}
		}
	}

	printf("%I64d\n", extension);

	return 0;
}
