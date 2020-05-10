#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<pair<long long, long long>, long long> &a, const pair<pair<long long, long long>, long long> &b)
{
	return a.first.first < b.first.first || a.first.first == b.first.first&&a.first.second < b.first.second;
}

int main()
{
	vector<pair<pair<long long, long long>,long long>> cheese;
	vector<long long> row;
	vector<pair<long long, long long>> range;
	int t, z;
	long long n, m, k;
	long long i, j;
	long long input1, input2, input3;
	long long index;
	long long prev;
	long long left[10001], right[10001];
	pair<long long, long long> min[10001];
	long long max;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld %lld", &n, &m, &k);

		for (i = 0; i < k; i++)
		{
			scanf("%lld %lld", &input1, &input2, &input3);

			cheese.push_back(pair<pair<long long, long long>, long long>(pair<long long, long long>(input1, input2), input3));
		}

		sort(cheese.begin(), cheese.end(), func);

		index = 0;
		prev = -1;

		row.push_back(0);
		range.push_back(pair<long long, long long>(0, 0));

		for (i = 0; i < cheese.size(); i++)
		{
			if (cheese[i].first.first != prev)
			{
				index++;

				prev = cheese[i].first.first;
				row.push_back(prev); 
				range[index - 1].second = i;
				range.push_back(pair<long long, long long>(i, 0));
			}
		}

		range[index].second = i;

		left[0] = 0;
		right[0] = 0;
		max = 0;

		for (i = 0; i < row.size(); i++)
		{

		}
	}
}