#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	int i;
	long long input;
	vector<long long> arr;
	long long lmax = 0;
	long long cur = 0;
	long long left;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	left = lmax = cur = arr[n - 1];

	for (i = n - 2; i >= 0; i--)
	{
		if (arr[i] < --left)
		{
			left = arr[i];
		}

		if (left <= 0)
		{
			break;
		}

		lmax += left;
	}

	printf("%I64d\n", lmax);

	return 0;
}