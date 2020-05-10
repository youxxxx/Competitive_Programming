#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k;

		scanf("%d %d", &n, &k);

		char input[10000];
		string str, sol;

		scanf("%s", input);

		str = input;
		int left;

		left = n / 2 - (k - 1);

		for (int i = 0; i < k - 1; i++)
		{
			sol.append("()");
		}

		for (int i = 0; i < left; i++)
		{
			sol.push_back('(');
		}

		for (int i = 0; i < left; i++)
		{
			sol.push_back(')');
		}

		vector<pair<int, int>> op;

		for (int i = 0; i < n; i++)
		{
			if (str[i] != sol[i])
			{
				int ptr;

				for (int j = i + 1; j < n; j++)
				{
					if (str[j] == sol[i])
					{
						ptr = j;

						break;
					}
				}

				op.push_back(make_pair(i + 1, ptr + 1));

				for (int j = i; j <= i + (ptr - i) / 2; j++)
				{
					char temp;

					temp = str[j];
					str[j] = str[ptr - (j - i)];
					str[ptr - (j - i)] = temp;
				}
			}
		}

		printf("%d\n", op.size());

		for (int i = 0; i < op.size(); i++)
		{
			printf("%d %d\n", op[i].first, op[i].second);
		}
	}

	return 0;
}