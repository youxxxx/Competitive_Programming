#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n;

bool safe(int x)
{
	return x >= 0 && x < n;
}
int main()
{
	string s, t;
	char input[201];

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	int n, m;

	n = s.size();
	m = t.size();

	int l[2] = { 0, };
	int r[2] = { 0, };
	int depth = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			depth++;

			l[0]++;
		}

		else
		{
			depth--;

			r[0]++;
		}

		if (depth < 0)
		{
			depth++;

			l[0]++;
		}
	}

	r[0] += depth;

	depth = 0;

	for (int i = 0; i < m; i++)
	{
		if (t[i] == '(')
		{
			depth++;

			l[1]++;
		}

		else
		{
			depth--;

			r[1]++;
		}

		if (depth < 0)
		{
			depth++;

			l[1]++;
		}
	}

	r[1] += depth;

	int lmax;

	lmax = l[0] > l[1] ? l[0] : l[1];

	if (r[0] > lmax)
	{
		lmax = r[0];
	}

	if (r[1] > lmax)
	{
		lmax = r[1];
	}

	pair<int, int> dp[401][401];

	dp[0][0] = { 0, 0 };

	string sol[401][401];

	for (int i = 1; i <= lmax; i++)
	{
		int curs, curt;

		curs = dp[i - 1][0].first;
		curt = dp[i - 1][0].second;

		if (curs < n && s[curs] == '(')
		{
			curs++;
		}

		if (curt < m && t[curt] == '(')
		{
			curt++;
		}

		dp[i][0] = { curs,curt };

		sol[i][0] = sol[i - 1][0];

		sol[i][0].push_back('(');
	}

	for (int i = 1; i <= lmax; i++)
	{
		int curs, curt;

		for (int j = 1; j < i; j++)
		{
			int cands, candt;

			cands = dp[i][j - 1].first;
			candt = dp[i][j - 1].second;

			if (cands < n && s[cands] == ')')
			{
				cands++;
			}

			if (candt < m && t[candt] == ')')
			{
				candt++;
			}

			curs = cands;
			curt = candt;

			sol[i][j] = sol[i][j - 1];

			sol[i][j].push_back(')');

			cands = dp[i - 1][j].first;
			candt = dp[i - 1][j].second;

			if (cands < n && s[cands] == '(')
			{
				cands++;
			}

			if (candt < m && t[candt] == '(')
			{
				candt++;
			}

			if (cands > curs)
			{
				curs = cands;
				curt = candt;

				sol[i][j] = sol[i - 1][j];

				sol[i][j].push_back('(');
			}
		}

		curs = dp[i][i - 1].first;
		curt = dp[i][i - 1].second;

		if (curs < n && s[curs] == ')')
		{
			curs++;
		}

		if (curt < m && t[curt] == ')')
		{
			curt++;
		}

		dp[i][i] = { curs,curt };

		sol[i][i] = sol[i][i - 1];

		sol[i][i].push_back(')');
	}

	printf("%s\n", sol[lmax][lmax].c_str());

	return 0;
}