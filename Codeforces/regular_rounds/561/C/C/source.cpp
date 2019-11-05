#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	vector<long long> arr;
	long long input;
	long long ptr1, ptr2;
	long long sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(abs(input));
	}

	sort(arr.begin(), arr.end());

	ptr1 = 0;
	ptr2 = 1;

	while (ptr1 < n)
	{
		if (ptr1 == ptr2)
		{
			ptr2++;
		}

		while (ptr2 < n && arr[ptr1] * 2 >= arr[ptr2])
		{
			ptr2++;
		}

		sol += ptr2 - ptr1 - 1;

		ptr1++;
	}

	printf("%lld\n", sol);

	return 0;
}