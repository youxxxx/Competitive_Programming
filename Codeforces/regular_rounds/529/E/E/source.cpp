#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int tot = 0, cur = 0;
	int min = 1;
	int n, i, j;
	char input[1000001];
	vector<int> height, acc;
	int lmin = 10000002;
	int cnt = 0;

	string str;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			tot++;
		}

		else
		{
			tot--;
		}
		
		height.push_back(tot);

		if (tot < min)
		{
			min = tot;
		}
	}

	if (n % 2 || tot > 2 || tot == 0 || tot < -2 || min < -2)
	{
		printf("0\n");

		return 0;
	}

	if (tot == 2)
	{
		for (i = n - 1; i >= 0; i--)
		{
			if (height[i] < lmin)
			{
				lmin = height[i];
			}

			if (lmin < 2)
			{
				break;
			}

			if (str[i] == '(' && height[i] >= 2)
			{
				cnt++;
			}
		}

		for (j = i; j >= 0; j--)
		{
			if (height[j] < 0)
			{
				printf("0\n");

				return 0;
			}
		}
	}

	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			if (height[i] < lmin)
			{
				lmin = height[i];
			}

			if (lmin < -2)
			{
				printf("0\n");

				return 0;
			}
		}

		for (i = 0; i < n; i++)
		{
			if (str[i] == ')')
			{
				cnt++;
			}

			if (height[i] < 0)
			{
				break;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
