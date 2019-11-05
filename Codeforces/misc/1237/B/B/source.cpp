#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int in[100001], out[100001];
	int fine[100001] = { 0, };
	int input;
	int i, j, ptr;
	int sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		in[i] = input;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		out[i] = input;
	}

	ptr = 0;

	for (i = 0; i < n; i++)
	{
		if (fine[in[i]])
		{
			continue;
		}

		if (in[i] != out[ptr])
		{
			for (j = ptr; j < n; j++)
			{
				if (out[j] == in[i])
				{
					break;
				}

				fine[out[j]] = 1;
			}

			ptr = j + 1;
		}

		else
		{
			ptr++;
		}
	}

	for (i = 1; i <= n; i++)
	{
		sol += fine[i];
	}

	printf("%d\n", sol);

	return 0;
}