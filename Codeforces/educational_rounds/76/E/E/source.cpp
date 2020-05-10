#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first&&a.second > b.second;
}

vector<int> monster;
vector<pair<int, int>> hero;

int bin_search(int lb, int ub, int target)
{
	int next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (hero[next].first >= target)
	{
		return bin_search(next, ub, target);
	}

	return bin_search(lb, next, target);
}

int main()
{
	int a, b, c;
	int loc[200001];
	int n;
	int base = 0;
	int numtwo = 0, numthree = 0;

	scanf("%d %d %d", &a, &b, &c);
	n = a + b + c;

	for (int i = 0; i < a; i++)
	{
		int input;

		scanf("%d", &input);

		loc[input] = 1;

		base++;
	}

	for (int i = 0; i < b; i++)
	{
		int input;

		scanf("%d", &input);

		loc[input] = 2;

		numtwo++;
	}

	for (int i = 0; i < c; i++)
	{
		int input;

		scanf("%d", &input);

		loc[input] = 3;

		numthree++;
	}

	loc[0] = 0;

	int lmin = 99999999;

	int left = 1;

	for (int j = 1; j <= n; j++)
	{
		left = j;

		if (loc[j] == 3)
		{
			break;
		}

		if (loc[j] == 2)
		{
			numtwo--;
		}
	}

	int right = n;

	for (int j = n; j >= left; j--)
	{
		right = j;

		if (loc[j] == 2)
		{
			break;
		}

		if (loc[j] == 3)
		{
			numthree--;
		}
	}

	if (right == left)
	{
		printf("0\n");

		return 0;
	}

	for (int i = 0; i <= n; i++)
	{
		if (i != 0 && loc[i] != 1)
		{
			base++;
		}

		if (i > 1)
		{
			if (loc[i - 1] == 3 && right != i - 1)
			{
				numthree--;
			}
		}

		if (loc[i] == 1)
		{
			base--;
		}

		if (i > right)
		{
			right = i;
		}

		if (left < i + 1)
		{
			left = i + 1;

			for (int j = i + 1; j <= right; j++)
			{
				left = j;

				if (loc[j] == 3)
				{
					break;
				}

				if (loc[j] != 1)
				{
					numtwo--;
				}
			}
		}

		/*
		if (base + n - ((left - i) + (n - right) + 2) < lmin)
		{
			lmin = base + n - ((left - i) + (n - right) + 2);
		}
		*/

		if (base + (numtwo<numthree?numtwo:numthree) < lmin)
		{
			lmin = base + (numtwo<numthree ? numtwo : numthree);
		}
	}

	printf("%d\n", lmin);

	return 0;
}