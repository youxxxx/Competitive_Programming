#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	char input[201];
	string str;

	vector<int> sol;

	scanf("%d", &n);

	scanf("%s", input);
	str = input;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'B')
		{
			cnt++;
		}
	}

	if (cnt % 2)
	{
		if (!(n % 2))
		{
			printf("-1\n");

			return 0;
		}

		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] == 'W')
			{
				sol.push_back(i);

				if (str[i] == 'B')
				{
					str[i] = 'W';
				}

				else
				{
					str[i] = 'B';
				}
			}
		}
	}

	else
	{
		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] == 'B')
			{
				sol.push_back(i);

				if (str[i] == 'W')
				{
					str[i] = 'B';
				}

				else
				{
					str[i] = 'W';
				}
			}
		}
	}
	
	printf("%d\n", sol.size());

	for (int i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}