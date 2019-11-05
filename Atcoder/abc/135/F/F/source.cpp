#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

#define MOD 1000000007

using namespace std;

int main()
{
	char input[500001];
	string s, t;
	int qn, qm;
	int n, m;
	int ptr1, ptr2;
	int i, j;
	int lmax = 0, cnt;
	int f[500001] = { 0, };

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	qn = n = s.size();
	qm = m = t.size();

	if (n < m)
	{
		n *= (m + n - 1) / n;
	}

	n *= 2;

	f[0] = 0;

	j = 0;

	for (i = 1; i < m; i++)
	{
		while (j > 0 && t[i] != t[j])
		{
			j = f[j - 1];
		}

		if (t[i] == t[j])
		{
			f[i] = ++j;
		}
	}

	for (i = 0; i < n; i++)
	{
		ptr1 = i%qn;

		while (j > 0 && s[ptr1] != t[j%m])
		{
			j = f[(j + m - 1) % m];
		}

		if (s[ptr1] == t[j%m])
		{
			j++;
		}

		if (j > lmax)
		{
			lmax = j;
		}
	}

	if (lmax > n / 2)
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", lmax / m);
	}

	return 0;
}
