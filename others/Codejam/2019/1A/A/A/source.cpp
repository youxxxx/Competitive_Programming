#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int sol;

int dfs(vector<string> &tot, int &lim)
{
	int i;
	int ptr;
	vector<string> bin[26];
	int nlim[26] = { 0, };
	string str;
	int sum = 0;
	int ret;

	if (!lim)
	{
		return 0;
	}

	if (tot.size() < 2)
	{
		return 0;
	}

	lim -= 2;
	sol += 2;

	if (!lim)
	{
		return 2;
	}

	for (i = 0; i < tot.size(); i++)
	{
		str = tot[i];

		if (str.empty())
		{
			continue;
		}

		ptr = str.back() - 'A';

		str.pop_back();

		bin[ptr].push_back(str);

		nlim[ptr]++;
	}

	for (i = 0; i < 26; i++)
	{
		nlim[i] = nlim[i] / 2 * 2;

		if (nlim[i] > lim)
		{
			nlim[i] = lim;
		}

		if (bin[i].size() >= 2)
		{
			ret = dfs(bin[i], nlim[i]);

			lim -= ret;

			sum += ret;
		}
	}

	return ret;
}

int main()
{
	int t, z;
	int n;
	int i;
	int lim[26];
	char input[100];
	string str;
	vector<string> bin[26];
	int ptr;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		sol = 0;

		for (i = 0; i < 26; i++)
		{
			lim[i] = 0;

			bin[i].clear();
		}

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			ptr = str.back() - 'A';

			str.pop_back();

			bin[ptr].push_back(str);

			lim[ptr]++;
		}

		for (i = 0; i < 26; i++)
		{
			lim[i] = lim[i] / 2 * 2;

			if (lim[i])
			{
				dfs(bin[i], lim[i]);
			}
		}

		printf("Case #%d: %d\n", z + 1, sol);
	}

	return 0;
}