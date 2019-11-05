#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m, temp;
	char input[1000001];
	string str, sol;
	int ub;
	int i, j;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &m);

		scanf("%s", input);

		str = input;

		sol.clear();

		temp = m;

		for (i = 0; i < n; i++)
		{
			if (str[i] == '0')
			{
				if (i - sol.size() < temp)
				{
					temp -= i - sol.size();

					sol.push_back('0');
				}

				else
				{
					ub = sol.size();

					for (j = 0; j < i - ub - temp; j++)
					{
						sol.push_back('1');
					}

					sol.push_back('0');

					for (j = 0; j < temp; j++)
					{
						sol.push_back('1');
					}

					break;
				}
			}
		}

		if (i == n)
		{
			ub = sol.size();

			for (j = 0; j < n - ub; j++)
			{
				sol.push_back('1');
			}
		}

		else
		{
			for (j = i + 1; j < n; j++)
			{
				sol.push_back(str[j]);
			}
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}