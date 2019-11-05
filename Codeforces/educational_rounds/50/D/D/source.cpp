#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	long long int n, m;
	long long int input;
	long long int i, ptr1 = 0, ptr2 = 0;
	long long int sum1 = 0, sum2 = 0;
	long long int sol = 0;
	vector<long long int> a, b;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		sum1 += input;

		a.push_back(input);
	}

	scanf("%I64d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%I64d", &input);

		sum2 += input;

		b.push_back(input);
	}

	if (sum1 != sum2)
	{
		printf("-1");

		return 0;
	}

	sum1 = a[ptr1++];
	sum2 = b[ptr2++];

	while (ptr1 < n&&ptr2 < m)
	{
		if (sum1 == sum2)
		{
			sol++;
			sum1 = a[ptr1++];
			sum2 = b[ptr2++];
		}

		else if (sum1 < sum2)
		{
			sum1 += a[ptr1++];
		}

		else
		{
			sum2 += b[ptr2++];
		}
	}

	if (ptr1 < n || ptr2 < m || sum1!=0 || sum2!=0)
	{
		sol++;
	}

	printf("%I64d", sol);

	return 0;
}