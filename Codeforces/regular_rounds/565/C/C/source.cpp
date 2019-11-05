#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int last[6] = { 0 };
	int arr[6] = { 4,8,15,16,23,42 };
	int i, j;
	int n;
	int input;
	int del = 0;
	int sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		for (j = 0; j < 6; j++)
		{
			if (input == arr[j])
			{
				if (j == 0)
				{
					last[0]++;
				}

				else
				{
					if (last[j - 1] == last[j])
					{
						del++;
					}

					else
					{
						last[j]++;
					}
				}

				break;
			}
		}
	}

	sol = del;

	for (i = 4; i >= 0; i--)
	{
		sol += last[i] - last[i + 1];

		last[i] = last[i + 1];
	}

	printf("%d\n", sol);

	return 0;
}