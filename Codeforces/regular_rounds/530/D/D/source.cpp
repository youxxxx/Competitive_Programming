#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

static long long sum = 0;
vector<vector<int>> tree;
vector<int> parent;
vector<int> emp;
vector<long long> s;

long long res(int cur,long long acc)
{
	int i;
	long long min = 10000000000000000;
	long long cand;

	if (s[cur]!=-1 && acc > s[cur])
	{
		printf("-1\n");

		exit(0);
	}

	if (tree[cur].empty())
	{
		if (s[cur] == -1)
		{
			return 0;
		}

		sum += s[cur] - acc;

		return s[cur] - acc;
	}

	if (s[cur] != -1)
	{
		for (i = 0; i < tree[cur].size(); i++)
		{
			cand = res(tree[cur][i], s[cur]);

			if (cand < min)
			{
				min = cand;
			}
		}
		/*
		if (s[cur] - acc < min)
		{
			min = s[cur] - acc;
		}
		*/

		sum += s[cur] - acc;

		return s[cur] - acc;
	}
	
	else
	{
		for (i = 0; i < tree[cur].size(); i++)
		{
			cand = res(tree[cur][i], acc);

			if (cand < min)
			{
				min = cand;
			}
		}

		sum -= min*(tree[cur].size() - 1);

		return min;
	}
}

int main()
{
	int n;
	int i;
	int input1;
	long long input2;

	scanf("%d", &n);

	parent.push_back(0);
	parent.push_back(0);
	s.push_back(0);

	for (i = 0; i <= n; i++)
	{
		tree.push_back(emp);
	}

	for (i = 2; i <= n; i++)
	{
		scanf("%d", &input1);

		tree[input1].push_back(i);

		parent.push_back(input1);
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &input2);

		s.push_back(input2);
/*
		if (input2 != -1)
		{
			sum += input2;
		}
*/
	}

	res(1, 0);

	printf("%I64d\n", sum);

	return 0;
}