#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;
	long long z, input;
	int i;
	int ptr1, ptr2;
	int cnt = 0;

	scanf("%d %I64d", &n, &z);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	ptr1 = 0;
	ptr2 = n / 2;

	while (ptr1 < n / 2 && ptr2 < n)
	{
		if (arr[ptr2] - arr[ptr1] >= z)
		{
			cnt++;

			ptr1++;
			ptr2++;
		}

		else
		{
			ptr2++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}