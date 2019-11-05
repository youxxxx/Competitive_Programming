#include<cstdio>
#include<string>

using namespace std;

int main()
{
	char input[1001];
	string s, t;
	int n, m, q;
	int table[1000];
	bool match[1000] = { false, };
	int i, j, k;
	int sum;
	int lb, ub;

	scanf("%d %d %d", &n, &m, &q);

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	table[0] = -1;
	k = -1;

	for (i = 1; i < m; i++)
	{
		while (k >= 0 && t[k + 1] != t[i])
		{
			k = table[k];
		}

		if (t[k + 1] == t[i])
		{
			k++;
		}

		table[i] = k;
	}

	k = -1;

	for (i = 0; i < n; i++)
	{
		while (k >= 0 && t[k + 1] != s[i])
		{
			k = table[k];
		}

		if (t[k + 1] == s[i])
		{
			k++;
		}

		if (k == m - 1)
		{
			match[i - m + 1] = true;

			k = table[k];
		}
	}

	for (i = 0; i < q; i++)
	{
		sum = 0;

		scanf("%d %d", &lb, &ub);

		for (j = lb - 1; j <= ub - m; j++)
		{
			sum += match[j];
		}

		printf("%d\n", sum);
	}

	return 0;
}