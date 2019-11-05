#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, input;
	long long i;
	long long cur;
	long long sol[1000];
	long long acc;
	long long lacc[1000], racc[1000];
	long long min, max;
	vector<long long> left, right;
	bool visited[1000] = { false };
	bool all, change;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		left.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		right.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (left[i] > i || right[n - i - 1] > i)
		{
			printf("NO");

			return 0;
		}
	}

	cur = n;

	while (1)
	{
		all = true;
		change = false;

		for (i = 0; i < n; i++)
		{
			all = (all&&visited[i]);
		}

		if (all)
		{
			break;
		}

		acc = 0;

		for (i = 0; i < n; i++)
		{
			lacc[i] = acc;

			if (!visited[i])
			{
				if (!left[i] && !right[i])
				{
					max = i;

					sol[i] = cur;

					acc++;

					change = true;
				}
			}
		}

		if (!change)
		{
			printf("NO");

			return 0;
		}

		acc = 0;

		for (i = n - 1; i >= 0; i--)
		{
			racc[i] = acc;

			if (!visited[i] && !left[i] && !right[i])
			{
				visited[i] = true;

				acc++;
			}
		}
		
		for (i = 1; i < n; i++)
		{
			if (!visited[i])
			{
				if (left[i] - lacc[i] < 0)
				{
					printf("NO");

					return 0;
				}

				left[i] -= lacc[i];
			}
		}

		for (i = n - 2; i >= 0; i--)
		{
			if (!visited[i])
			{
				if (right[i] - racc[i] < 0)
				{
					printf("NO");

					return 0;
				}

				right[i] -= racc[i];
			}
		}

		cur--;
	}
	
	printf("YES\n");

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}