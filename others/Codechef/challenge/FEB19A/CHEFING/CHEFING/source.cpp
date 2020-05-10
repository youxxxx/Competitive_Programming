#include<cstdio>
#include<string>

using namespace std;

int main()
{
	long long first, other;
	long long sol;
	int t, z;
	int n, i, j;
	char input[200];
	string str;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		first = 0;

		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		for (j = 0; j < str.size(); j++)
		{
			first |= 1 << str[j] - 'a';
		}

		for (i = 0; i < n - 1; i++)
		{
			other = 0;

			scanf("%s", input);

			str = input;

			for (j = 0; j < str.size(); j++)
			{
				other |= 1 << str[j] - 'a';
			}

			first &= other;
		}

		sol = 0;

		while (first)
		{
			sol += first % 2;

			first /= 2;
		}

		printf("%lld\n", sol);
	}

	return 0;
}