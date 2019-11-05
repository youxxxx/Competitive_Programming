#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 998244353

using namespace std;

int main()
{
	vector<int> arr;
	int n;
	int i;
	int input;
	int lmax = 0, lidx;
	int ptr1, ptr2;
	int cur;

	scanf("%d", &n);

	arr.clear();

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		if (input > lmax)
		{
			lmax = input;

			lidx = i;
		}
	}
	
	ptr1 = lidx - 1;
	ptr2 = lidx + 1;
	cur = lmax;

	while (ptr1 >= 0 || ptr2 < n)
	{
		if (ptr1 == -1)
		{
			if (arr[ptr2] >= cur)
			{
				printf("NO\n");

				return 0;
			}

			cur = arr[ptr2++];
		}

		else if (ptr2 == n)
		{
			if (arr[ptr1] >= cur)
			{
				printf("NO\n");

				return 0;
			}

			cur = arr[ptr1--];
		}

		else
		{
			if (arr[ptr1] > arr[ptr2])
			{
				if (arr[ptr1] >= cur)
				{
					printf("NO\n");

					return 0;
				}

				cur = arr[ptr1--];
			}

			else
			{
				if (arr[ptr2] >= cur)
				{
					printf("NO\n");

					return 0;
				}

				cur = arr[ptr2++];
			}
		}
	}

	printf("YES\n");

	return 0;
}