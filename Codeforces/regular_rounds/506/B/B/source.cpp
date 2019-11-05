#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<int> prob;
	int input;
	int i, max = 1, cons = 0, cur;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		prob.push_back(input);
	}

	cur = prob[0];
	cons = 1;
	max = 1;

	for (i = 1; i < n; i++)
	{
		if (prob[i] <= cur * 2)
		{
			if (++cons > max)
			{
				max = cons;
			}
		}

		else
		{
			cons = 1;
		}

		cur = prob[i];
	}

	printf("%d", max);

	return 0;
}