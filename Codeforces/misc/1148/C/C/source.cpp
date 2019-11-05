#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> moves;
int loc[300001], arr[300001];

void swap(int a, int b)
{
	int vala, valb;
	int loca, locb;
	int temp;

	moves.push_back(pair<int, int>(a, b));

	vala = arr[a];
	valb = arr[b];

	arr[b] = vala;
	arr[a] = valb;

	loc[vala] = b;
	loc[valb] = a;
}

int main()
{
	int i;
	int cur, temp, temp2;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);

		loc[arr[i]] = i;
	}

	for (i = 0; i < n / 2 - 1; i++)
	{
		cur = n / 2 - i;

		if (arr[cur] != cur)
		{
			if (abs(loc[cur] - cur) >= n / 2)
			{
				swap(loc[cur], cur);
			}

			else
			{
				if (loc[cur] <= n / 2)
				{
					swap(loc[cur], n);
					swap(cur, n);
				}

				else
				{
					swap(loc[cur], 1);
					swap(1, n);
					swap(cur, n);
				}
			}
		}

		cur = n / 2 + 1 + i;

		if (arr[cur] != cur)
		{
			if (abs(loc[cur] - cur) >= n / 2)
			{
				swap(loc[cur], cur);
			}

			else
			{
				if (loc[cur] > n / 2)
				{
					swap(loc[cur], 1);
					swap(cur, 1);
				}

				else
				{
					swap(loc[cur], n);
					swap(1, n);
					swap(cur, 1);
				}
			}
		}
	}

	if (arr[1] != 1)
	{
		swap(1, n);
	}

	printf("%d\n", moves.size());

	for (i = 0; i < moves.size(); i++)
	{
		printf("%d %d\n", moves[i].first, moves[i].second);
	}

	return 0;
}
