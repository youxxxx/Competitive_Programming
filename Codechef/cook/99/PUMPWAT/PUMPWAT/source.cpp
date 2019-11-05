#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	return a.first > b.first;
}

int main()
{
	int t, n;
	vector<long long> hill;
	vector<pair<long long, long long>> sorted;
	int i, j, z;
	int input;
	int prev;
	int cnt;
	int sol, sol2;
	int pump;
	bool inc, dec, right;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		prev = 0;
		cnt = 1;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			hill.push_back(input);

			sorted.push_back(pair<long long, long long>(input, i));
		}

		sort(sorted.begin(), sorted.end(), func);

		/*

		if (hill[1] > hill[0])
		{
			inc = true;

			pump = 0;

			right = false;
		}

		else
		{
			inc = false;

			//dec = true;

			pump = hill[0];

			right = true;
		}

		for (i = 1; i < n - 1; i++)
		{
			
			if (inc)
			{
				if (hill[i + 1] < hill[i])
				{
					inc = false;

					//dec = true;
					if (!right)
					{
						right = true;

						cnt++;
					}
				}
			}

			else// if(dec)
			{
				if (hill[i + 1] > hill[i])
				{
					inc = true;

					//dec = false;

					right = false;
				}
			}
			

			if (right)
			{
				if()
			}
		}

		if (!inc&&!right)
		{
			cnt++;
		}
		*/

		if (sorted[0].second == 0 || sorted[0].second == n - 1)
		{
			sol = 1;
		}

		else
		{
			for (i = 0; i < n - 1; i++)
			{
				if (abs(sorted[i].second - sorted[i + 1].second) == 1 || (sorted[i + 1].second == 0 || sorted[i + 1].second == n - 1))
				{
					break;
				}
			}
			
			if (i < n - 1 && sorted[i + 1].second == 0 || sorted[i + 1].second == n - 1)
			{
				if (sorted[i + 1].second == 0)
				{
					for (j = 1; j <= i; j++)
					{
						if (sorted[j].second < sorted[0].second)
						{
							break;
						}
					}

					if (j == i + 1)
					{
						sol = 2;
					}

					else
					{
						sol = i + 2;
					}
				}

				else
				{
					for (j = 1; j <= i; j++)
					{
						if (sorted[j].second > sorted[0].second)
						{
							break;
						}
					}

					if (j == i + 1)
					{
						sol = 2;
					}

					else
					{
						sol = i + 2;
					}
				}
			}

			else
			{
				sol = i + 2;
			}

			for (i = 1; i < n - 1; i++)
			{
				for (j = 0; j < i; j++)
				{
					if (abs(sorted[i].second - sorted[j].second) == 1)
					{
						break;
					}
				}

				if (j < i)
				{
					sol2 = j + 2;
					
					break;
				}
			}

			if (sol2 < sol)
			{
				sol = sol2;
			}
		}

		printf("%d\n", sol);

		hill.clear();
		sorted.clear();
	}

	return 0;
}