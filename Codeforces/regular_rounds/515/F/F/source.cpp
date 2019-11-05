#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

pair<long long, long long> c2r(pair<long long, long long> &input)
{
	pair<long long, long long> output;
	long long max;

	max = input.first;

	if (input.second > max)
	{
		max = input.second;
	}

	output.first = max;
	output.second = (max - input.second) - (max - input.first);

	return output;
}

pair<long long, long long> r2c(pair<long long, long long> &input)
{
	pair<long long, long long> output;

	output.first = output.second = input.first;

	if (input.second < 0)
	{
		output.first += input.second;
	}

	else
	{
		output.second -= input.second;
	}

	return output;
}

int main()
{
	vector<pair<long long, long long>> point;
	vector<pair<long long, int>> range;
	pair<long long, long long> cur;
	pair<long long, long long> left, right;
	pair<long long, long long> ccoord1, rcoord1;
	pair<long long, long long> ccoord2, rcoord2;
	long long input1, input2;
	long long start, end, level;
	long long min;
	int n, i;
	long long dp[2][2];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		ccoord1.first = input1;
		ccoord1.second = input2;

		rcoord1 = c2r(ccoord1);

		point.push_back(rcoord1);
	}

	sort(point.begin(), point.end(), func);

	level = point[0].first;

	for (i = 1; i < n; i++)
	{
		if (level != point[i].first)
		{
			range.push_back(pair<long long, int>(level, i));

			level = point[i].first;
		}
	}

	range.push_back(pair<long long, int>(level, n));

	rcoord1 = point[0];
	rcoord2 = point[range[0].second - 1];

	ccoord1 = r2c(rcoord1);
	ccoord2 = r2c(rcoord2);

	dp[0][0] = ccoord1.first + ccoord1.second + abs(rcoord1.second - rcoord2.second);
	dp[0][1] = ccoord2.first + ccoord2.second + abs(rcoord1.second - rcoord2.second);

	start = 0;

	for (i = 1; i < range.size(); i++)
	{
		rcoord1 = point[start];
		rcoord2 = point[range[i - 1].second - 1];

		ccoord1 = r2c(rcoord1);
		ccoord2 = r2c(rcoord2);

		left = point[range[i - 1].second];
		right = point[range[i].second - 1];

		cur = r2c(point[range[i - 1].second]);

		min = dp[!(i % 2)][1] + abs(cur.first - ccoord1.first) + abs(cur.second - ccoord1.second);

		if (dp[!(i % 2)][0] + abs(cur.first - ccoord2.first) + abs(cur.second - ccoord2.second) < min)
		{
			min = dp[!(i % 2)][0] + abs(cur.first - ccoord2.first) + abs(cur.second - ccoord2.second);
		}

		dp[i % 2][0] = min + abs(left.second - right.second);

		cur = r2c(point[range[i].second - 1]);

		min = dp[!(i % 2)][1] + abs(cur.first - ccoord1.first) + abs(cur.second - ccoord1.second);

		if (dp[!(i % 2)][0] + abs(cur.first - ccoord2.first) + abs(cur.second - ccoord2.second) < min)
		{
			min = dp[!(i % 2)][0] + abs(cur.first - ccoord2.first) + abs(cur.second - ccoord2.second);
		}

		dp[i % 2][1] = min + abs(left.second - right.second);

		start = range[i - 1].second;
	}

	min = dp[!(i % 2)][0];

	if (dp[!(i % 2)][1] < min)
	{
		min = dp[!(i % 2)][1];
	}

	printf("%I64d", min);

	return 0;
}

/*
bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	long long amax, bmax;

	amax = a.first;

	if (a.second > amax)
	{
		amax = a.second;
	}

	bmax = b.first;

	if (b.second > bmax)
	{
		bmax = b.second;
	}

	return amax < bmax || amax == bmax && a.first < b.first || amax == bmax && a.first == b.first && a.second > b.second;
}

int main()
{
	vector<pair<long long, long long>> point;
	vector<pair<long long,pair<long long,long long>>> range;
	pair<long long, long long> data;
	int start;
	int n, i, j;
	long long input1, input2, level, min, max;
	long long dir[2][2];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		point.push_back(pair<long long, long long>(input1, input2));
	}

	sort(point.begin(), point.end(), func);

	start = 0;

	max = point[0].first;

	if (point[0].second > max)
	{
		max = point[0].second;
	}

	level = max;

	for (i = 1; i < n; i++)
	{
		max = point[i].first;

		if (point[i].second > max)
		{
			max = point[i].second;
		}

		if (level != max)
		{
			data.first = start;
			data.second = i - 1;

			range.push_back(pair<long long, pair<long long, long long>>(level, data));

			start = i;
			level = max;
		}
	}

	data.first = start;
	data.second = n - 1;

	range.push_back(pair<long long, pair<long long, long long>>(level, data));

	dir[0][0] = point[range[0].second.first].first + point[range[0].second.first].second + (range[0].first - point[range[0].second.first].second) + (range[0].first - point[range[0].second.second].first);
	dir[0][1] = point[range[0].second.second].first + point[range[0].second.second].second + (range[0].first - point[range[0].second.first].second) + (range[0].first - point[range[0].second.second].first);

	for (i = 1; i < range.size(); i++)
	{
		min = dir[!(i % 2)][0] + abs(point[range[i - 1].second.second].first - point[range[i].second.first].first) + abs(point[range[i - 1].second.second].second - point[range[i].second.first].second);

		if (min > dir[!(i % 2)][1] + abs(point[range[i - 1].second.first].first - point[range[i].second.first].first) + abs(point[range[i - 1].second.first].second - point[range[i].second.first].second))
		{
			min = dir[!(i % 2)][1] + abs(point[range[i - 1].second.first].first - point[range[i].second.first].first) + abs(point[range[i - 1].second.first].second - point[range[i].second.first].second);
		}

		dir[i % 2][0] = min + (range[i].first - point[range[i].second.first].second) + (range[i].first - point[range[i].second.second].first);

		min = dir[!(i % 2)][0] + abs(point[range[i - 1].second.second].first - point[range[i].second.second].first) + abs(point[range[i - 1].second.second].second - point[range[i].second.second].second);

		if (min > dir[!(i % 2)][1] + abs(point[range[i - 1].second.first].first - point[range[i].second.first].first) + abs(point[range[i - 1].second.first].second - point[range[i].second.first].second))
		{
			min = dir[!(i % 2)][1] + abs(point[range[i - 1].second.first].first - point[range[i].second.first].first) + abs(point[range[i - 1].second.first].second - point[range[i].second.first].second);
		}

		dir[i % 2][1] = min + (range[i].first - point[range[i].second.first].second) + (range[i].first - point[range[i].second.second].first);
	}

	min = dir[!(i % 2)][0];

	if (min > dir[!(i % 2)][1])
	{
		min = dir[!(i % 2)][1];
	}

	printf("%I64d", min);

	return 0;
}
*/