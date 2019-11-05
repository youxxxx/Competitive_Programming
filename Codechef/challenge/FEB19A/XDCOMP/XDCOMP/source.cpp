#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

vector<long long> arr;
long long sol;
long long tot;
vector<int> *graph;
long long x;

struct report
{
public:
	long long cur0;
	long long curx;
	long long pre0;
	long long prex;
	long long val;
	bool phase0;
	bool phasex;

	report()
	{
		cur0 = curx = pre0 = prex = val = 0;

		phase0 = phasex = false;
	}

	report operator+=(const report &rhs) {
		/*
		cur0 = (cur0 * (!(rhs.cur0) + rhs.cur0)) % MOD;
		curx = (curx * (!(rhs.curx) + rhs.curx)) % MOD;
		pre0 = (pre0 * (!(rhs.pre0) + rhs.pre0)) % MOD;
		prex = (prex * (!(rhs.prex) + rhs.prex)) % MOD;
		*/
		cur0 = rhs.cur0;
		curx = rhs.curx;
		pre0 = rhs.pre0;
		prex = rhs.prex;

		val ^= rhs.val;
		phase0 = phase0 || rhs.phase0;
		phasex = phasex || rhs.phasex;

		return *this;
	}
};

report dfs(int cur, int parent)
{
	int i;
	report rvalue;
	report ret;
	int next;
	bool newcx = false;
	bool newc0 = false;
	bool newpx = false;
	bool newp0 = false;
	long long even = 1, odd = 1;

	if (graph[cur].size() == 1 && parent != 0)
	{
		if (arr[cur] == x)
		{
			rvalue.curx = 1;
			sol = (sol + 1) % MOD;
			rvalue.phasex = true;
		}

		rvalue.val = arr[cur];

		return rvalue;
	}

	/*
	rvalue.cur0 = 1;
	rvalue.curx = 1;
	rvalue.pre0 = 1;
	rvalue.prex = 1;
	*/

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		ret = dfs(next, cur);

		rvalue += ret;

		even = (even * ((ret.cur0 + ret.curx + ret.pre0 + ret.prex) + 1)) % MOD;
		odd = (odd * (ret.curx + ret.prex)) % MOD;
		newc0 = newc0 || !!ret.cur0;
		newcx = newcx || !!ret.curx;
		newp0 = newp0 || !!ret.pre0;
		newpx = newpx || !!ret.prex;
	}

	/*
	rvalue.cur0 *= (long long)newc0;
	rvalue.curx *= (long long)newcx;
	rvalue.pre0 *= (long long)newp0;
	rvalue.prex *= (long long)newpx;
	*/

	rvalue.val ^= arr[cur];

	if (graph[cur].size() >= 3)
	{
		/*
		if (graph[cur].size() % 2)
		{
			rvalue.pre0 = even;
			rvalue.prex = 0;
			rvalue.cur0 = 0;
			rvalue.curx = 0;
		}

		else
		{
			rvalue.pre0 = (even - odd + MOD) % MOD;
			rvalue.prex = odd;
			rvalue.cur0 = 0;
			rvalue.curx = 0;
		}`
		*/

		rvalue.pre0 = (even - odd + MOD) % MOD;
		rvalue.prex = odd;
		rvalue.cur0 = 0;
		rvalue.curx = 0;

		return rvalue;
	}


	if (rvalue.val == 0 && (rvalue.phase0 || rvalue.phasex))
	{
		rvalue.phase0 = true;
		rvalue.phasex = false;

		rvalue.prex = (rvalue.prex + rvalue.curx) % MOD;
		rvalue.curx = 0;

		rvalue.cur0 = (rvalue.cur0 + 1) % MOD;
		rvalue.pre0 = (rvalue.pre0 + rvalue.prex) % MOD;

		if (tot == x)
		{
			sol = (sol + rvalue.prex + 1) % MOD;
		}
	}

	else if (rvalue.val == x)
	{
		rvalue.phasex = true;
		rvalue.phase0 = false;

		rvalue.pre0 = (rvalue.pre0 + rvalue.cur0) % MOD;
		rvalue.cur0 = 0;

		rvalue.curx = (rvalue.curx + 1) % MOD;
		rvalue.prex = (rvalue.prex + rvalue.pre0) % MOD;

		if (tot == 0)
		{
			sol = (sol + rvalue.pre0 + 1) % MOD;
		}
	}

	return rvalue;
}

int main()
{
	int n;
	int i;
	long long input;
	int u, v;
	report ret;

	//freopen("input.txt", "r", stdin);

	arr.push_back(0);

	scanf("%d %lld", &n, &x);

	graph = new vector<int>[n + 1];	

	tot = 0;

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &input);

		tot ^= input;

		arr.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	if (tot != 0 && tot != x)
	{
		printf("0\n");

		return 0;
	}
	
	sol = 0;

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			ret = dfs(i, 0);

			break;
		}
	}
	/*
	if (tot == x)
	{
		sol += (sol + ret.pre0 + 1) % MOD;
	}
	*/
	printf("%lld\n", sol);

	return 0;
}