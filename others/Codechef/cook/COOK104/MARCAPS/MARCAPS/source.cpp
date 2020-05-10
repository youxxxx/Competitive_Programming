#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.first < b.first;
}

bool func2(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.second < b.second;
}

int main()
{
	vector<long long> arr, ori, sol, ord;
	vector<pair<long long, int>> ind;
	int n;
	int t, z;
	int start;
	int ptr;
	int i;
	long long input;
	long long base;
	int dir;
	bool valid;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);

			ind.push_back(pair<long long, int>(input, i));
		}

		sort(arr.begin(), arr.end());
		ori = arr;

		sort(ind.begin(), ind.end(), func);

		for (i = 1; i < n; i++)
		{
			if (arr[i] != arr[0])
			{
				break;
			}
		}

		if (i == n)
		{
			printf("No\n");

			arr.clear();
			sol.clear();
			ori.clear();
			ind.clear();
			ord.clear();

			continue;
		}

		ptr = i;
		dir = 1;

		valid = true;

		for (i = 0; i < n; i++)
		{
			if (arr[ptr] == ori[i])
			{
				dir *= -1;

				if (arr[(ptr + dir + arr.size()) % arr.size()] == ori[i])
				{
					valid = false;
					break;
				}

				else
				{
					ptr = (ptr + dir + arr.size()) % arr.size();

					sol.push_back(arr[ptr]);

					arr.erase(arr.begin() + ptr);

					if (arr.empty())
					{
						break;
					}

					if (dir == -1)
					{
						ptr = (ptr + dir + arr.size()) % arr.size();
					}

					else
					{
						ptr %= arr.size();
					}
				}
			}

			else
			{
				sol.push_back(arr[ptr]);

				arr.erase(arr.begin() + ptr);

				if (arr.empty())
				{
					break;
				}

				if (dir == -1)
				{
					ptr = (ptr + dir + arr.size()) % arr.size();
				}

				else
				{
					ptr %= arr.size();
				}
			}
		}

		if (!valid)
		{
			printf("No\n");
		}

		else
		{
			printf("Yes\n");

			for (i = 0; i < n; i++)
			{
				ord.push_back(0);
			}

			for (i = 0; i < n; i++)
			{
				ord[ind[i].second] = sol[i];
			}

			for (i = 0; i < n; i++)
			{
				printf("%lld ", ord[i]);
			}

			printf("\n");
		}

		arr.clear();
		sol.clear();
		ori.clear();
		ind.clear();
		ord.clear();
	}

	return 0;
}