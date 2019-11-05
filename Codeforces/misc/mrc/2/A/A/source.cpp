#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, s;
	vector<int> a, b;
	int i;
	int input;

	scanf("%d %d", &n, &s);

	a.push_back(0);
	b.push_back(0);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		a.push_back(input);
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		b.push_back(input);
	}

	if (!a[1])
	{
		printf("NO\n");
	}

	else
	{
		if (a[s])
		{
			printf("YES\n");
		}

		else if (b[s])
		{
			for (i = s + 1; i <= n; i++)
			{
				if (a[i] && b[i])
				{
					break;
				}
			}

			if (i <= n)
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}