#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

class node
{
public:
	long long val;
	long long lb;
	long long ub;
	node *left;
	node *right;

	long long create(long long arr[], long long lb_input, long long ub_input)
	{
		long long ret = 0;

		lb = lb_input;
		ub = ub_input;

		if (lb == ub)
		{
			val = arr[lb];

			lb = NULL;
			ub = NULL;

			return val;
		}

		left = new node;
		right = new node;

		ret += left->create(arr, lb, (lb + ub) / 2);
		ret += right->create(arr, (lb + ub) / 2 + 1, ub);

		val = ret;

		return val;
	}

	void subtract(long long idx)
	{
		val -= idx;

		if (lb != ub)
		{
			if (idx <= left->ub)
			{
				left->subtract(idx);
			}

			else
			{
				right->subtract(idx);
			}
		}
	}

	long long search(long long target)
	{
		if (target == val)
		{
			return ub;
		}

		else if (target <= left->val)
		{
			return left->search(target);
		}

		else
		{
			return right->search(target - left->val);
		}
	}
};

class psum
{
public:
	node *root;
	long long n;

	psum(long long arr[], long long n_input)
	{
		n = n_input;
		root = new node;

		root->create(arr, 1, n);
	}

	void subtract(long long idx)
	{
		root->subtract(idx);
	}

	long long search(long long target)
	{
		return root->search(target);
	}
};

int main()
{
	long long n;
	long long sum[400001];
	long long arr[200001];
	long long sol[200001];
	long long diff[200001];
	long long input;
	long long i;
	long long target;
	psum *p;

	scanf("%lld", &n);

	for (i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &diff[i]);
	}

	p = new psum(arr, n);

	for (i = n - 1; i >= 0; i--)
	{
		target = p->search(diff[i]);

		sol[i] = target + 1;

		p->subtract(target + 1);
	}

	for (i = 0; i < n; i++)
	{
		printf("%lld ", sol[i]);
	}

	return 0;
}