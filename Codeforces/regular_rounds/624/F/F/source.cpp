#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>

#define N 200000

using namespace std;

long long tree[N + 1] = { 0, };

void add(long long idx, long long val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		tree[idx] += val;
	}
}


long long get(long long idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

long long psum(long long l, long long r)
{
	return get(r) - get(l);
}

long long tree2[N + 1] = { 0, };

void add2(long long idx, long long val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		tree2[idx] += val;
	}
}

long long get2(long long idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += tree2[idx];
	}

	return rvalue;
}

long long psum2(long long l, long long r)
{
	return get2(r) - get2(l);
}

using namespace std;

int main()
{
	long long n;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &n);

	vector<pair<long long, long long>> points;
	vector<long long> coord(200001), speed(200001), scaled;
	map<long long, long long> list;

	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &coord[i]);

		scaled.push_back(coord[i]);
	}

	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &speed[i]);
	}

	sort(scaled.begin(), scaled.end());

	for (long long i = 0; i < n; i++)
	{
		list[scaled[i]] = i + 1;
	}

	for (long long i = 0; i < n; i++)
	{
		points.push_back({ speed[i],list[coord[i]] });
	}

	sort(points.begin(), points.end());

	long long sol = 0;

	for (long long i = 0; i < n; i++)
	{
		long long x, v;

		x = points[i].second;
		v = points[i].first;

		sol += get(x - 1)*scaled[x - 1] - get2(x - 1);

		add(x, 1);
		add2(x, scaled[x-1]);
	}

	printf("%lld\n", sol);

	return 0;
}