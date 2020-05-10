#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		char input[100001];
		string s, t;

		scanf("%s", input);
		s = input;
		scanf("%s", input);
		t = input;

		int n, m;
		int next[100000][26];

		n = s.size();
		m = t.size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				next[i][j] = -1;
			}
		}

		int last[26];

		memset(last, -1, sizeof(last));

		for (int i = 0; i < n; i++)
		{
			last[s[i] - 'a'] = i;
		}

		for (int i = 0; i < n; i++)
		{
			int ub;

			if (last[s[i] - 'a'] >= i)
			{
				ub = i + n;
			}

			else
			{
				ub = i;
			}

			for (int j = last[s[i] - 'a']; j < ub; j++)
			{
				next[j%n][s[i] - 'a'] = i;
			}

			if (last[s[i] - 'a'] == i)
			{
				next[i][s[i] - 'a'] = i;
			}

			last[s[i] - 'a'] = i;
		}

		long long sol;
		int ptr;

		ptr = next[n - 1][t[0] - 'a'];
		sol = ptr + 1;

		if (sol == 0)
		{
			printf("-1\n");

			continue;
		}

		bool valid = true;

		for (int i = 1; i < m; i++)
		{
			int nptr;

			nptr = next[ptr][t[i] - 'a'];

			if (nptr == -1)
			{
				valid = false;

				break;
			}

			long long add;

			add = (n + nptr - ptr) % n;

			add += n * !(add);

			sol += add;

			ptr = nptr;
		}

		if (!valid)
		{
			printf("-1\n");
		}

		else
		{
			printf("%lld\n", (sol + n - 1) / n);
		}
	}

	return 0;
}