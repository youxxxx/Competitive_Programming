#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int val(char input)
{
	int rvalue;

	switch (input)
	{
	case 'R':
		rvalue = 0;
		break;
	case 'S':
		rvalue = 1;
		break;
	case 'P':
		rvalue = 2;
		break;
	}

	return rvalue;
}

char val2(int input)
{
	char rvalue;

	switch (input)
	{
	case 0:
		rvalue = 'R';
		break;
	case 1:
		rvalue = 'S';
		break;
	case 2:
		rvalue = 'P';
		break;
	}

	return rvalue;
}

int main()
{
	int t, z;
	bool taken[3];
	int n;
	int i, j, k;
	string strategy;
	vector<string> op;
	vector<int> idx[3];
	int target;
	string str;
	char input[1000];
	bool valid;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		op.clear();
		strategy.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			op.push_back(str);
		}

		valid = true;

		for (i = 0; i < 500; i++)
		{
			for (j = 0; j < 3; j++)
			{
				taken[j] = false;

				idx[j].clear();
			}

			for (j = 0; j < op.size(); j++)
			{
				target = val(op[j][i%op[j].size()]);

				taken[target] = true;

				idx[target].push_back(j);
			}

			if (taken[0] && taken[1] && taken[2])
			{
				valid = false;

				break;
			}

			for (j = 0; j < 3; j++)
			{
				if (!taken[j])
				{
					if (!taken[(j + 2) % 3])
					{
						strategy.push_back(val2(j));

						op.clear();

						break;
					}

					strategy.push_back(val2((j + 1) % 3));

					for (k = idx[(j + 2) % 3].size() - 1; k >= 0; k--)
					{
						op.erase(op.begin() + idx[(j + 2) % 3][k]);
					}

					break;
				}
			}

			if (op.empty())
			{
				break;
			}
		}

		if (!valid)
		{
			printf("Case #%d: IMPOSSIBLE\n", z + 1);
		}

		else
		{
			printf("Case #%d: %s\n", z + 1, strategy.c_str());
		}
	}

	return 0;
}