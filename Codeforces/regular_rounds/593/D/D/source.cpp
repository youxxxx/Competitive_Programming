#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n, m, k;
	int i, j;
	int row[100001] = { 0, };
	int col[100001] = { 0, };
	//set<int> rows[100001];
	//set<int> cols[100001];
	//set<int>::iterator it;
	int x, y;
	int up, down, left, right;
	int h = 0, v = 0;

	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);

		row[x]++;
		col[y]++;

		//rows[x].insert(y);
		//cols[y].insert(x);
	}

	up = 1;
	down = n;
	left = 1;
	right = m;

	while (1)
	{
		if (up == down)
		{
			for (i = left; i <= right; i++)
			{
				if (col[i] == v + 1)
				{
					for (j = i + 1; j <= right; j++)
					{
						if (col[i] != v + 1)
						{
							break;
						}
					}

					if (j == right + 1)
					{
						printf("Yes\n");

						return 0;
					}

					printf("No\n");

					return 0;
				}
			}

			printf("Yes\n");

			return 0;
		}

		if (row[up] - h > 1 || row[up] - h == 1 && col[right] - v != down - up + 1)
		{
			printf("No\n");

			return 0;
		}

		if (row[up] - h == 1 && col[right] == down - up + 1)
		{
			right--;

			h++;
		}

		up++;

		if (right == left)
		{
			for (i = up; i <= down; i++)
			{
				if (row[i] == h + 1)
				{
					for (j = i + 1; j <= down; j++)
					{
						if (row[i] != h + 1)
						{
							break;
						}
					}

					if (j == down + 1)
					{
						printf("Yes\n");

						return 0;
					}

					printf("No\n");

					return 0;
				}
			}

			printf("Yes\n");

			return 0;
		}

		if (col[right] - v > 1 || col[right] - v == 1 && row[down] - h != right - left + 1)
		{
			printf("No\n");

			return 0;
		}

		if (col[right] - v == 1 && row[down] - h == right - left + 1)
		{
			down--;

			v++;
		}

		right--;

		if (up == down)
		{
			for (i = right; i >= left; i--)
			{
				if (col[i] == v + 1)
				{
					for (j = i - 1; j >= left; j--)
					{
						if (col[i] != v + 1)
						{
							break;
						}
					}

					if (j == left - 1)
					{
						printf("Yes\n");

						return 0;
					}

					printf("No\n");

					return 0;
				}
			}

			printf("Yes\n");

			return 0;
		}

		if (row[down] - h > 1 || row[down] - h == 1 && col[left] - v != down - up + 1)
		{
			printf("No\n");

			return 0;
		}

		if (row[down] - h == 1 && col[left] - v == down - up + 1)
		{
			left++;

			h++;
		}

		down--;

		if (right == left)
		{
			for (i = down; i >= up; i--)
			{
				if (row[i] == h + 1)
				{
					for (j = i - 1; j >= up; j--)
					{
						if (row[i] != h + 1)
						{
							break;
						}
					}

					if (j == up - 1)
					{
						printf("Yes\n");

						return 0;
					}

					printf("No\n");

					return 0;
				}
			}

			printf("Yes\n");

			return 0;
		}

		if (col[left] - v > 1 || col[left] - v == 1 && row[up] - h != right - left + 1)
		{
			printf("No\n");

			return 0;
		}

		if (col[left] - v == 1 && row[up] - h == right - left + 1)
		{
			up++;

			v++;
		}

		left++;
	}

	return 0;
}