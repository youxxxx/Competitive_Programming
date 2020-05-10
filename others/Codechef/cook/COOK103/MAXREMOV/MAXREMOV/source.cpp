#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

class comp
{
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b) const
	{
		return a.second > b.second;
	}
};

int main()
{
	int t, z;
	int n, k;
	int i, j;
	vector<pair<long long, long long>> arr;
	vector<pair<int, int>> two, three;
	long long input1, input2;
	int cnt;
	long long val[2];	
	vector<long long> open, close;
	long long height;
	long long tot;
	long long cand, max;
	int prev2, prev3;
	int ptr1, ptr2;
	int lmin, rmin;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &k);

		val[0] = val[1] = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld", &input1, &input2);

			arr.push_back(pair<long long, long long>(input1, input2));

			open.push_back(input1);
			close.push_back(input2);
		}

		sort(arr.begin(), arr.end(), func);
		sort(open.begin(), open.end());
		sort(close.begin(), close.end());

		i = j = 0;
		height = 0;

		tot = 0;

		while (i <= n&&j <= n)
		{
			if (i!=n && open[i] < close[j] + 1)
			{
				if (height == k)
				{
					two.push_back(pair<int, int>(prev2, open[i]));

					tot += open[i] - prev2;
				}
				
				else if (height == k + 1)
				{
					three.push_back(pair<int, int>(prev3, open[i]));
				}

				height++;

				if (height == k)
				{
					prev2 = open[i];
				}

				else if (height == k + 1)
				{
					prev3 = open[i];
				}

				i++;
			}

			else
			{
				if (height == k)
				{
					two.push_back(pair<int, int>(prev2, close[j] + 1));

					tot += close[j] + 1 - prev2;
				}

				else if (height == k + 1)
				{
					three.push_back(pair<int, int>(prev3, close[j] + 1));
				}

				height--;

				if (height == k)
				{
					prev2 = close[j] + 1;
				}

				else if (height == k + 1)
				{
					prev3 = close[j] + 1;
				}

				j++;
			}
		}

		max = -n - 1;

		for (i = 0; i < n; i++)
		{
			cand = 0;

			for (j = 0; j < two.size(); j++)
			{
				if (arr[i].second < two[j].first)
				{
					break;
				}

				if (arr[i].first >= two[j].second)
				{
					continue;
				}

				lmin = arr[i].first > two[j].first ? arr[i].first : two[j].first;
				rmin = arr[i].second < two[j].second - 1 ? arr[i].second : two[j].second - 1;

				cand -= rmin - lmin + 1;
			}

			for (j = 0; j < three.size(); j++)
			{
				if (arr[i].second < three[j].first)
				{
					break;
				}

				if (arr[i].first >= three[j].second)
				{
					continue;
				}

				lmin = arr[i].first > three[j].first ? arr[i].first : three[j].first;
				rmin = arr[i].second < three[j].second - 1 ? arr[i].second : three[j].second - 1;

				cand += rmin - lmin + 1;
			}

			if (cand > max)
			{
				max = cand;
			}
		}

		printf("%lld\n", tot + max);

		arr.clear();
		open.clear();
		close.clear();
		two.clear();
		three.clear();
	}

	return 0;
}