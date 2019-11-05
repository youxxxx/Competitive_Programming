#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

string s, t;
int n, m;

int bin_search(int lb, int ub)
{
	int next;
	int i;
	int match = 0;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	for (i = next; i < n; i++)
	{
		if (s[i] == t[match])
		{
			match++;
		}

		if (match == m)
		{
			break;
		}
	}

	if (match == m)
	{
		return bin_search(next, ub);
	}

	match = 0;

	for (i = 0; i < n - next; i++)
	{
		if (s[i] == t[match])
		{
			match++;
		}

		if (match == m)
		{
			break;
		}
	}

	if (match == m)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	char input[200001];
	int i;
	int cand, sol;
	int first[200001], last[200001];
	int match;

	memset(first, -1, sizeof(first));

	scanf("%s", input);
	s = input;
	n = s.size();
	scanf("%s", input);
	t = input;
	m = t.size();

	sol = bin_search(0, n - m + 1);

	/*
	for (i = 0; i < n; i++)
	{
		if (first[s[i] - 'a'] == -1)
		{
			first[s[i] - 'a'] = i;
		}

		last[s[i] - 'a'] = i;
	}
	*/

	match = 0;

	for (i = 0; i < n; i++)
	{
		if (s[i] == t[match])
		{
			first[match++] = i;
		}

		if (match == m)
		{
			break;
		}
	}

	match = m - 1;

	for (i = n - 1; i >= 0; i--)
	{
		if (s[i] == t[match])
		{
			last[match--] = i;
		}

		if (match == -1)
		{
			break;
		}
	}

	for (i = 0; i < m - 1; i++)
	{
		cand = last[i + 1] - first[i] - 1;

		if (cand > sol)
		{
			sol = cand;
		}
	}

	printf("%d\n", sol);

	return 0;
}