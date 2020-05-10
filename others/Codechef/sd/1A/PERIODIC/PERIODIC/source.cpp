#include<cstdio>
#include<vector>

using namespace std;

int gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int n, t;
	vector<pair<int,int>> lit;
	int input;
	int i, j;
	int min, max;
	int diff, diff2;
	bool imp, inf;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);

		imp = false;
		inf = true;
		min = -1;
		max = -1;

		for (j = 0; j < n; j++)
		{
			scanf("%d", &input);

			if (input > 0)
			{
				lit.push_back(pair<int, int>(input, j));
			}
		}

		if (lit.size() < 2)
		{
			printf("inf\n");

			lit.clear();

			continue;
		}

		min = lit[0].first;

		for (j = 1; j < lit.size(); j++)
		{
			if (lit[j].first > min)
			{
				min = lit[j].first;
			}

			diff = (lit[j].second - lit[j - 1].second) - (lit[j].first - lit[j - 1].first);

			if (diff < 0)
			{
				imp = true;
				
				break;
			}

			if (diff != 0)
			{
				inf = false;
			}

			if (diff != 0)
			{
				if (max == -1)
				{
					max = diff;
				}

				else
				{
					max = gcd(max, diff);
				}
			}

			if (max!=-1 && max < min)
			{
				imp = true;

				break;
			}
		}

		if (imp)
		{
			printf("impossible\n");
		}

		else if (inf)
		{
			printf("inf\n");
		}

		else
		{
			printf("%d\n", max);
		}

		lit.clear();
	}

	return 0;
}