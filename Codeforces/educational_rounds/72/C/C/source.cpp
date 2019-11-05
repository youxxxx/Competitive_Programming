#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long tc, cases;
	long long n;
	string str;
	char input[200001];
	long long i, j, pw;
	long long ptr;
	long long sol;
	long long val;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		ptr = -1;

		sol = 0;

		for (i = 0; i < n; i++)
		{
			if (str[i] == '0')
			{
			}

			else
			{
				sol++;

				val = 1;

				for (j = i + 1; j < n; j++)
				{
					val = val * 2 + (str[j] - '0');

					if (val > j - ptr)
					{
						break;
					}

					if (val == j - ptr)
					{
					}
					sol++;
				}

				ptr = i;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}