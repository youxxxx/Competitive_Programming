#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<functional>

using namespace std;

vector<int> arr;
int n, m;

int bin_search(int lb, int ub)
{
	vector<int> sol;
	int next;
	int prev = 0;
	int i;
	int l, u;

	if (ub - lb < 2)
	{
		return ub;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	for (i = 0; i < n; i++)
	{
		if (next >= m - arr[i])
		{
			u = next - (m - arr[i]);

			if (prev > u)
			{
				if (arr[i] < prev)
				{
					if (next < prev - arr[i])
					{
						return bin_search(next, ub);
					}
				}

				else
				{
					prev = arr[i];
				}
			}
		}

		else
		{
			if (arr[i] < prev)
			{
				if (next < prev - arr[i])
				{
					return bin_search(next, ub);
				}
			}

			else
			{
				prev = arr[i];
			}
		}
	}

	return bin_search(lb, next);
}

int main()
{
	int i;
	int input;

	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	printf("%d\n", bin_search(-1, m));

	return 0;
}