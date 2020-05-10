#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int n, k;
	vector<int> arr;
	vector<int> lim;
	vector<int> c;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end(), greater<int>());

	c.push_back(0);

	for (int i = 0; i < k; i++)
	{
		int input;

		scanf("%d", &input);

		c.push_back(input);
	}

	int acc = 0;

	for (int i = k; i >= 1; i--)
	{
		for (int j = acc; j < c[i]; j++)
		{
			lim.push_back(i);
		}

		acc = c[i];
	}

	int available = 0;

	vector<int> room;
	vector<vector<int>> sol;
	vector<int> emp;

	for (int i = 0; i < n; i++)
	{
		if (room.empty())
		{
			room.push_back(1);

			sol.push_back(emp);

			sol.back().push_back(arr[i]);

			if (room.back() == lim.size())
			{
				available++;
			}
		}

		else
		{
			if (room.back() == lim.size() || lim[room.back()] < arr[i])
			{
				room.push_back(1);

				sol.push_back(emp);

				sol.back().push_back(arr[i]);

				if (room.back() == lim.size())
				{
					available++;
				}

			}

			else
			{
				int lb, ub;

				lb = available - 1;
				ub = room.size() - 1;

				for (int next = (lb + ub) / 2 + (lb + ub) % 2; ub - lb > 1; next = (lb + ub) / 2 + (lb + ub) % 2)
				{
					if (lim[room[next]] >= arr[i])
					{
						ub = next;
					}

					else
					{
						lb = next;
					}
				}

				room[ub]++;

				sol[ub].push_back(arr[i]);

				if (room[ub] == lim.size())
				{
					available++;
				}
			}
		}
	}

	printf("%d\n", sol.size());

	for (int i = 0; i < sol.size(); i++)
	{
		printf("%d", sol[i].size());

		for (int j = 0; j < sol[i].size(); j++)
		{
			printf(" %d", sol[i][j]);
		}

		printf("\n");
	}

	return 0;
}