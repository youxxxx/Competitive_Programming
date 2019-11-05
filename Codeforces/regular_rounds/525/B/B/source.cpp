#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	vector<long long> arr;
	long long input;
	int i;
	int ptr = 1;
	long long cur = 0;

	scanf("%d %d", &n, &k);

	arr.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	if (n == 1)
	{
		printf("%I64d\n", arr[1]);

		for (i = 0; i < k - 1; i++)
		{
			printf("0\n");
		}

		return 0;
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < k; i++)
	{
		printf("%I64d\n", arr[ptr] - arr[ptr - 1]);

		while (ptr < n&&arr[ptr] == arr[ptr + 1])
		{
			ptr++;
		}

		if (ptr == n)
		{
			arr[ptr - 1] = arr[ptr];
		}

		else
		{
			ptr++;
		}
	}

	return 0;
}