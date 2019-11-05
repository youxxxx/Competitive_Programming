#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[100001];
	long long n, m;
	string s, t;
	vector<long long> pos[26];
	vector<long long>::iterator ret;
	long long i, j;
	long long sol = 0;
	bool change = true;

	scanf("%s", input);
	s = input;
	n = s.size();
	scanf("%s", input);
	t = input;
	m = t.size();

	for (i = 0; i < n; i++)
	{
		pos[s[i] - 'a'].push_back(i);
	}

	j = 0;

	for (i = 0; i < m; i++)
	{
		ret = lower_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), j);

		if (ret == pos[t[i] - 'a'].end())
		{
			if (!change)
			{
				printf("-1\n");

				return 0;
			}

			j = 0;

			sol += n;

			i--;

			change = false;
		}

		else
		{
			change = true;

			j = *ret + 1;
		}
	}

	sol += j;

	printf("%lld\n", sol);

	return 0;
}
