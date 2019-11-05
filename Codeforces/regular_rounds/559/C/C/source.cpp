#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.first < b.first || a.first == b.first&&a.second < b.second;
}

int main()
{
	int n, m;
	int i;
	long long input;
	vector<long long> arr1, arr2;
	vector<pair<long long, int>> tot;
	vector<pair<long long, long long>> boy;
	long long sol = 0;
	long long lmax = 0;
	bool valid = true;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr1.push_back(input);

		if (input > lmax)
		{
			lmax = input;
		}

		tot.push_back(pair<long long, int>(input, 0));
	}

	for (i = 0; i < m; i++)
	{
		scanf("%I64d", &input);

		arr2.push_back(input);

		tot.push_back(pair<long long, int>(input, 1));

		if (input < lmax)
		{
			valid = false;
		}
	}

	if (!valid)
	{
		printf("-1\n");

		return 0;
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	sort(tot.begin(), tot.end(), func);

	if (tot.back().second == 0)
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < n + m; i++)
	{
		if (tot[i].second == 0)
		{
			boy.push_back(pair<long long, long long>(tot[i].first, m - 1));

			sol += tot[i].first*(long long)m;
		}

		else
		{
			if (boy.empty())
			{
				printf("-1\n");

				return 0;
			}

			if ((tot[i].first - boy.back().first) > 0)
			{
				sol += (tot[i].first - boy.back().first);

				if (--boy.back().second == 0)
				{
					boy.pop_back();
				}
			}
		}
	}

	printf("%I64d\n", sol);

	return 0;
}
