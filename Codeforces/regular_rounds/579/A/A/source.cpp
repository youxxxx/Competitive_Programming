#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	int n;
	int i;
	vector<int> arr;
	int input;
	int start;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		arr.clear();

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);

			if (input == 1)
			{
				start = i;
			}
		}

		if (n == 1)
		{
			printf("YES\n");

			continue;
		}

		if (arr[(start + 1) % n] == n)
		{
			for (i = 1; i < n; i++)
			{
				if (arr[(start - i + n) % n] != i + 1)
				{
					break;
				}
			}

			if (i == n)
			{
				printf("YES\n");

				continue;
			}
		}

		else if (arr[(start + 1) % n] == 2)
		{
			for (i = 0; i < n; i++)
			{
				if (arr[(start + i) % n] != i + 1)
				{
					break;
				}
			}

			if (i == n)
			{
				printf("YES\n");

				continue;
			}
		}

		printf("NO\n");
	}

	return 0;
}