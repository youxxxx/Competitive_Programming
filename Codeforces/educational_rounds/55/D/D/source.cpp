#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<int> deg;
	vector<int> leaf, nonleaf;
	int sum = 0;
	int input;
	int i, j;
	int ptr = 0, delp;
	int min, nleaf;

	scanf("%d", &n);

	deg.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		sum += input;

		deg.push_back(input);

		if (input == 1)
		{
			leaf.push_back(i + 1);
		}

		else
		{
			nonleaf.push_back(i + 1);
		}
	}

	if (sum < (n - 1) * 2)
	{
		printf("NO\n");

		return 0;
	}

	if (n == 2)
	{
		printf("YES 1\n1\n1 2\n");

		return 0;
	}

	if (leaf.size() < 2)
	{
		while(leaf.size() < 2)
		{
			min = deg[nonleaf[0]];

			nleaf = nonleaf[0];

			delp = 0;

			for (i = 1; i < nonleaf.size(); i++)
			{
				if (deg[nonleaf[i]]!=1 && deg[nonleaf[i]] < min)
				{
					min = deg[nonleaf[i]];
					nleaf = nonleaf[i];
					delp = i;
				}
			}

			nonleaf.erase(nonleaf.begin() + delp);

			leaf.push_back(nleaf);
		}
	}

	if (nonleaf.size() == 1)
	{
		if (deg[nonleaf[0]] < leaf.size())
		{
			printf("NO\n");
		}

		else
		{
			printf("YES %d\n%d\n", nonleaf.size() + 1, leaf.size() + nonleaf.size() - 1);

			for (j = 0; j < leaf.size(); j++)
			{
				printf("%d %d\n", nonleaf[0], leaf[j]);
			}
		}

		return 0;
	}

	printf("YES %d\n%d\n", nonleaf.size() + 1, leaf.size() + nonleaf.size() - 1);

	for (j = 0; j < deg[nonleaf[0]] - 1; j++)
	{
		if (ptr < leaf.size() - 1)
		{
			printf("%d %d\n", nonleaf[0], leaf[ptr++]);
		}
	}

	printf("%d %d\n", nonleaf[0], nonleaf[1]);

	for (i = 1; i < nonleaf.size() - 1 ;i++)
	{
		printf("%d %d\n", nonleaf[i], nonleaf[i + 1]);

		for (j = 0; j < deg[nonleaf[0]] - 2; j++)
		{
			if (ptr < leaf.size() - 1)
			printf("%d %d\n", nonleaf[i], leaf[ptr++]);
		}
	}

	for (j = 0; j < deg[nonleaf.back()] - 1; j++)
	{
		if (ptr < leaf.size())
		printf("%d %d\n", nonleaf.back(), leaf[ptr++]);
	}

	return 0;
}