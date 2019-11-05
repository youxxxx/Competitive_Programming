#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	int i, j;
	vector<long long> arr;
	long long input, l;
	int input2;
	int p;
	long long d;
	bool *cut;
	bool left, right;
	long long total = 0;

	scanf("%d %d %I64d", &n, &m, &l);

	cut = new bool[n + 1];

	arr.push_back(0);

	for (i = 0; i < n; i++)
	{
		cut[i + 1] = false;

		scanf("%I64d", &input);

		arr.push_back(input);

		if (input > l)
		{
			cut[i + 1] = true;
		}
	}

	if (cut[1])
	{
		total++;
	}

	for (i = 2; i <= n; i++)
	{
		if (cut[i] && !cut[i - 1])
		{
			total++;
		}
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input2);

		if(input2)
		{
			scanf("%d %I64d", &p, &d);

			arr[p] += d;

			if (arr[p] > l && !cut[p])
			{
				left = right = false;

				cut[p] = true;

				if (p > 1 && cut[p - 1])
				{
					left = true;
				}

				if (p < n&&cut[p + 1])
				{
					right = true;
				}

				if (!left && !right)
				{
					total++;
				}

				else if (left&&right)
				{
					total--;
				}
			}
		}

		else
		{
			printf("%I64d\n", total);
		}
	}

	return 0;
}