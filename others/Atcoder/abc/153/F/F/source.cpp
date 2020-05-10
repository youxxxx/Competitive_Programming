#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>

#define N 600000

using namespace std;

int tree[N + 2] = { 0, };

void add(int idx, int val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		tree[idx] += val;
	}
}


int get(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

int psum(int l, int r)
{
	return get(r) - get(l);
}

int main()
{
	long long n, d, a;
	vector<pair<long long, long long>> arr;

	scanf("%lld %lld %lld", &n, &d, &a);

	for (long long i = 0; i < n; i++)
	{
		long long input1, input2;

		scanf("%lld %lld", &input1, &input2);

		arr.push_back({ input1,input2 });
	}

	sort(arr.begin(), arr.end());

	long long sol = 0;

	long long ptr = 0;

	for (long long i = 0; i < n; i++)
	{
		long long coord;
		long long stk;

		coord = arr[i].first - d * 2 > 1 ? arr[i].first - d * 2 : 1;

		while (arr[ptr].first < coord)
		{
			ptr++;
		}

		stk = psum(ptr, i);

		long long togo;

		togo = arr[i].second - stk;

		if (togo > 0)
		{
			long long q;

			q = (togo + a - 1) / a;
			add(i + 1, q*a);
			sol += q;
		}
	}

	printf("%lld\n", sol);

	return 0;
}