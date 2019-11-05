#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

long long n;

class node
{
public:
	long long lp;
	long long rp;
	node *left;
	node *right;

	node(long long lp_input, long long rp_input)
	{
		left = NULL;
		right = NULL;
		lp = lp_input;
		rp = rp_input;

		if (lp < n)
		{
			left = new node(lp + 1, rp);
		}

		if (rp < lp)
		{
			right = new node(lp, rp + 1);
		}
	}

	pair<long long, long long> dfs()
	{
		pair<long long, long long> lret, rret, rvalue;
		long long lmax;

		if (left == NULL&&right == NULL)
		{
			return pair<long long, long long>(1, 0);
		}

		if (right == NULL)
		{
			lret = left->dfs();

			rvalue.second = lret.first;
			rvalue.first = (lret.second + 1) % MOD;

			return rvalue;
		}

		if (left == NULL)
		{
			rret = right->dfs();

			rvalue.second = rret.first;
			rvalue.first = (rret.second + 1) % MOD;

			return rvalue;
		}

		lret = left->dfs();
		rret = right->dfs();

		rvalue.first = lret.second + rret.second + 1;
		rvalue.second = lret.first + rret.second > lret.second + rret.first ? lret.first + rret.second : lret.second + rret.first;

		rvalue.first %= MOD;
		rvalue.second %= MOD;

		return rvalue;
	}
};

pair<long long, long long> dfs(long long left,long long right)
{
	pair<long long, long long> lret, rret, rvalue;
	long long lmax;

	if (left == n&&right == n)
	{
		return pair<long long, long long>(1, 0);
	}

	if (right >= left)
	{
		lret = dfs(left + 1, right);

		rvalue.second = lret.first;
		rvalue.first = (lret.second + 1) % MOD;

		return rvalue;
	}

	if (left == n)
	{
		rret = dfs(left, right + 1);

		rvalue.second = rret.first;
		rvalue.first = (rret.second + 1) % MOD;

		return rvalue;
	}

	lret = dfs(left + 1, right);
	rret = dfs(left, right + 1);

	rvalue.first = lret.second + rret.second + 1;
	rvalue.second = lret.first + rret.second > lret.second + rret.first ? lret.first + rret.second : lret.second + rret.first;

	rvalue.first %= MOD;
	rvalue.second %= MOD;

	return rvalue;
}

int main()
{
	//node* root;
	pair<long long,long long> sol;

	scanf("%I64d", &n);

	//root = new node(0, 0);

	//sol = root->left->dfs();

	sol = dfs(1, 0);

	printf("%I64d\n", sol.first > sol.second ? sol.first : sol.second);

	return 0;
}