#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	vector<long long> arr;
	long long input;
	int i, j;
	int ptr1 = 0, ptr2 = 0;
	int lmax = 0;
	int interv[5000];
	int **dp;

	scanf("%d %d", &n, &k);

	dp = new int*[n];

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		interv[i] = -1;

		dp[i] = new int[k];
	}

	sort(arr.begin(), arr.end());

	while (ptr1 < n)
	{
		while (ptr2 < ptr1&&arr[ptr1] - arr[ptr2]>5)
		{
			ptr2++;
		}

		if (ptr1 - ptr2 + 1 > lmax)
		{
			lmax = ptr1 - ptr2 + 1;
		}

		interv[ptr1++] = ptr2;
	}

	for (i = 0; i < n; i++)
	{
		if (interv[i] != -1)
		{

		}
	}

	printf("%d\n", lmax);

	return 0;
}