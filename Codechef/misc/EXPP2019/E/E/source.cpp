#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<queue>

#define MOD 1000000007

using namespace std;

long long exp(long long val, long long pw)
{
	long long temp;
	long long res = 1;

	temp = pw;

	while (temp)
	{
		if (temp % 2)
		{
			res = res*val%MOD;
		}

		val = val*val%MOD;

		temp /= 2;
	}

	return res;
}

struct query
{
	long long n;
	long long k;
	long long m;
	long long index;
};

bool func(query &a, query &b)
{
	return a.n < b.n;
}

int main()
{
	int tc, cases;
	long long n, k, m;
	long long i;
	long long sol;
	vector<query> q;
	vector<pair<long long, long long>> sol;
	long long dp[2][200001];
	query cur;

	scanf("%d", &cases);	

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &n, &k, &m);

		cur.n = n;
		cur.k = k;
		cur.m = m;
		cur.index = tc;

		q.push_back(cur);
	}

	sort(q.begin(), q.end(), func);

	for()

	return 0;
}