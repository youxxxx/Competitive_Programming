#include<cstdio>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	char input[100001];
	string s, t, na;
	vector<int> pos;
	string sol;
	int i;
	int a = 0;
	int n, m;
	int idx;

	scanf("%s", input);
	t = input;

	n = t.size();

	for (i = 0; i < n; i++)
	{
		if (t[i] != 'a')
		{
			na.push_back(t[i]);
			pos.push_back(i);
		}
	}

	m = na.size();

	if (na.empty())
	{
		printf("%s", t.c_str());

		return 0;
	}

	if (na.size() % 2)
	{
		printf(":(\n");

		return 0;
	}

	for (i = 0; i < m / 2; i++)
	{
		if (na[i] != na[i + m / 2])
		{
			printf(":(\n");

			return 0;
		}
	}

	idx = pos[m / 2];

	for (i = idx; i < n; i++)
	{
		if (t[i] == 'a')
		{
			printf(":(\n");

			return 0;
		}
	}

	sol = t.substr(0, idx);

	printf("%s", sol.c_str());

	return 0;
}