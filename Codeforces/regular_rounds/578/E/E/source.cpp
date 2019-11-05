#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n, m;
	int ff[1000001];
	char input[1000001];
	string prev, cur;
	int i, j, k;

	scanf("%d", &n);

	scanf("%s", input);

	prev = input;

	for (i = 0; i < n - 1; i++)
	{
		scanf("%s", input);

		cur = input;

		k = 0;

		ff[0] = 0;

		for (j = 1; j < cur.size(); j++)
		{
			while (k > 0 & cur[k] != cur[j])
			{
				k = ff[k - 1];
			}

			if (cur[k] == cur[j])
			{
				ff[j] = ++k;
			}

			else
			{
				ff[j] = 0;
			}
		}

		m = prev.size();

		k = 0;

		for (j = m - (int)cur.size() > 0 ? m - (int)cur.size() : 0; j < m; j++)
		{
			while (k > 0 && prev[j] != cur[k])
			{
				k = ff[k - 1];
			}

			if (prev[j] == cur[k])
			{
				k++;
			}
		}

		if (k < cur.size())
		{
			prev.append(cur.substr(k, cur.size() - k));
		}
	}

	printf("%s\n", prev.c_str());

	return 0;
}