#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int i;
	int n;
	int ptr, ptr2, prev;
	long long d;
	vector<long long> arr;
	long long input;
	bool visited[100000];
	bool valid;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %lld", &n, &d);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);

			visited[i] = false;
		}

		sort(arr.begin() + 1, arr.end());

		valid = true;
		
		if (arr[1] >= arr[0] || arr[n - 1] <= arr[0])
		{
			if (arr[1] > arr[0] && arr[1] - arr[0] > d
				|| arr[n - 1] < arr[0] && arr[0] - arr[n - 1] > d)
			{
				printf("NO\n");

				arr.clear();

				continue;
			}

			for (i = 2; i < n; i++)
			{
				if (abs(arr[i] - arr[i - 1]) > d)
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}

			arr.clear();

			continue;
		}

		ptr = 1;

		while (++ptr < n&&arr[ptr] < arr[0]);

		ptr2 = ptr - 1;
		prev = ptr2;
		visited[ptr2] = true;

		while (--ptr2 > 0)
		{
			while (ptr2 > 0 && abs(arr[prev] - arr[ptr2]) <= d)
			{
				ptr2--;
			}

			if (ptr2 == 0 || abs(arr[prev] - arr[ptr2]) > d)
			{
				ptr2++;
			}

			if (prev == ptr2)
			{
				valid = false;

				break;
			}

			prev = ptr2;

			visited[ptr2] = true;
		}

		/*
		if (ptr2 != 0 && valid)
		{
			n = n;
		}
		*/

		if (valid)
		{
			visited[1] = true;
			prev = 1;

			for (i = 2; i < n; i++)
			{
				if (!visited[i])
				{
					if (abs(arr[prev] - arr[i]) > d)
					{
						valid = false;

						break;
					}

					visited[i] = true;
					prev = i;
				}
			}
		}

		if (valid)
		{
			printf("YES\n");

			arr.clear();

			continue;
		}

		for (i = 0; i < n; i++)
		{
			visited[i] = false;
		}

		ptr = n;

		while (--ptr > 0 && arr[ptr] > arr[0]);

		ptr2 = ptr + 1;
		prev = ptr2;
		visited[ptr2] = true;

		valid = true;

		while (++ptr2 < n)
		{
			while (ptr2 < n && abs(arr[prev] - arr[ptr2]) <= d)
			{
				ptr2++;
			}

			if (ptr2 == n || abs(arr[prev] - arr[ptr2]) > d)
			{
				ptr2--;
			}

			if (prev == ptr2)
			{
				valid = false;

				break;
			}

			prev = ptr2;

			visited[ptr2] = true;
		}

		/*
		if (ptr2 != n && valid)
		{
			n = n;
		}
		*/

		if (valid)
		{
			visited[n - 1] = true;
			prev = n - 1;

			for (i = n - 2; i >= 1; i--)
			{
				if (!visited[i])
				{
					if (abs(arr[prev] - arr[i]) > d)
					{
						valid = false;

						break;
					}

					visited[i] = true;
					prev = i;
				}
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}

		arr.clear();
	}

	return 0;
}
