#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	bool hand[200001] = { 0, }, hand2[200001];
	int zero = 0;
	int i;
	int input;
	int cur = 0, prev = 0;
	int one = 0;
	int idx;
	int sol;
	vector<int> arr;
	int last;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input == 0)
		{
			zero++;
		}

		else
		{
			hand[input] = true;
		}
	}

	one = -1;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		if (input == 1)
		{
			one = i;
		}
	}

	if (one == -1)
	{
		prev = 1;

		if (arr[0] != 0)
		{
			hand[arr[0]] = true;
		}

		for (i = 1; i < n; i++)
		{
			if (arr[i] == prev + 1)
			{
				hand[prev + 1] = true;
			}

			else if (hand[prev + 1])
			{
				hand[arr[i]] = true;

				prev++;
			}

			else
			{
				hand[arr[i]] = true;
			}
		}

		sol = 2 * n - prev;

		printf("%d\n", sol);

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] != i + 1)
		{
			break;
		}
	}

	if (i == n)
	{
		printf("0\n");

		return 0;
	}

	for (i = 1; i <= n; i++)
	{
		hand2[i] = hand[i];
	}

	prev = 1;

	for (i = one + 1; i < n; i++)
	{
		if (arr[i] != prev + 1)
		{
			break;
		}

		prev = arr[i];

		hand2[arr[i]] = true;
	}

	if (i == n&&arr[one - 1] == 0)
	{
		for (i = 0; i < one; i++)
		{
			if (arr[i] == prev + 1)
			{
				hand2[prev + 1] = true;
			}

			else if (hand2[prev + 1])
			{
				hand2[arr[i]] = true;

				prev++;
			}

			else
			{
				hand2[arr[i]] = true;
			}

			if (prev == n)
			{
				break;
			}
		}

		if (prev == n)
		{
			printf("%d\n", one);

			return 0;
		}
	}

	for (i = 0; i < one; i++)
	{
		hand[arr[i]] = true;
	}

	prev = 0;
	hand[1] = true;

	last = one;

	for (i = one + 1; i < n; i++)
	{
		idx = i;

		if (arr[idx] == prev + 1)
		{
			hand[prev + 1] = true;
		}

		else if (hand[prev + 1])
		{
			hand[arr[i]] = true;

			prev++;
		}

		else
		{
			hand[arr[i]] = true;
		}

		if (prev == n)
		{
			break;
		}
	}

	sol = 2 * n - prev;

	printf("%d\n", sol);

	return 0;
}