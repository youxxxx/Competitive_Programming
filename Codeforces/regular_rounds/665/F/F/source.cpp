#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

long long arr[300001];
bool swapstate[20] = { 0, };
bool revstate[20] = { 0, };

class node
{
public:
	long long val;
	node *left;
	node *right;
	bool flip;
	int depth;
	bool sflag;

	node(int l, int r, int depth_input)
	{
		flip = false;
		depth = depth_input;
		sflag = false;

		if (l == r)
		{
			val = arr[l];

			return;
		}

		const int mid = (l + r) / 2;

		left = new node(l, mid, depth_input - 1);
		right = new node(mid + 1, r, depth_input - 1);

		val = left->val + right->val;
	}

	void init(int l, int r, int depth, vector<node*>* access)
	{
		if (l == r)
		{
			return;
		}

		access[depth].push_back(this);

		const int mid = (l + r) / 2;

		left->init(l, mid, depth - 1, access);
		right->init(mid + 1, r, depth - 1, access);
	}

	long long psum(int l, int r, int lb, int ub)
	{
		if (l >= lb&&r <= ub)
		{
			return val;
		}

		if (r<lb || l>ub)
		{
			return 0;
		}

		if (l != r)
		{
			if (flip != revstate[depth])
			{
				flip = revstate[depth];

				node *temp = left;
				left = right;
				right = temp;

				left->flip = !(left->flip);
				right->flip = !(right->flip);
			}

			if (sflag != swapstate[depth])
			{
				sflag = swapstate[depth];

				node *temp = left;
				left = right;
				right = temp;
			}
		}

		const int mid = (l + r) / 2;

		if (ub <= mid)
		{
			return left->psum(l, mid, lb, ub);
		}

		if (lb >= mid + 1)
		{
			return right->psum(mid + 1, r, lb, ub);
		}

		return left->psum(l, mid, lb, ub) + right->psum(mid + 1, r, lb, ub);
	}

	long long replace(int l, int r, int idx,long long newval)
	{
		if (l == r)
		{
			const long long rvalue = newval - val;

			val = newval;

			return rvalue;
		}

		if (l != r)
		{
			if (flip != revstate[depth])
			{
				flip = revstate[depth];

				node *temp = left;
				left = right;
				right = temp;

				left->flip = !(left->flip);
				right->flip = !(right->flip);
			}

			if (sflag != swapstate[depth])
			{
				sflag = swapstate[depth];

				node *temp = left;
				left = right;
				right = temp;
			}
		}

		const int mid = (l + r) / 2;

		long long rvalue;

		if (idx <= mid)
		{
			rvalue = left->replace(l, mid, idx, newval);
		}

		else
		{
			rvalue = right->replace(mid + 1, r, idx, newval);
		}

		val += rvalue;

		return rvalue;
	}
};

vector<node*> access[19];

class tree
{
public:
	node *root;
	int height;
	int bound;

	tree(int n)
	{
		height = n;
		bound = (int)pow(2.0, n);
		root = new node(1, bound, n);

		root->init(1, bound, n, access);
	}

	void reverse(int k)
	{
		/*
		for (int i = 0; i < access[k].size(); i++)
		{
			node* next = access[k][i];

			next->flip = !(next->flip);
		}
		*/

		revstate[k] = !revstate[k];
	}

	void swap(int k)
	{
		k++;

		/*
		for (int i = 0; i < access[k].size(); i++)
		{
			node* next = access[k][i];

			node *temp = next->left;
			next->left = next->right;
			next->right = temp;
		}
		*/

		swapstate[k] = !swapstate[k];
	}

	void replace(int idx,int val)
	{
		root->replace(1, bound, idx, val);
	}

	long long psum(int lb, int ub)
	{
		return root->psum(1, bound, lb, ub);
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, q;

	scanf("%d %d", &n, &q);

	for (int i = 1; i <= (int)pow(2.0, n); i++)
	{
		scanf("%lld", &arr[i]);
	}

	tree t(n);

	for (int i = 0; i < q; i++)
	{
		int op;

		scanf("%d", &op);
		
		int a, b;
		long long c;

		switch (op)
		{
		case 1:
			scanf("%d %lld", &a, &c);
			t.replace(a, c);
			break;
		case 2:
			scanf("%d", &a);
			t.reverse(a);
			break;
		case 3:
			scanf("%d", &a);
			t.swap(a);
			break;
		case 4:
			scanf("%d %d", &a, &b);
			printf("%lld\n", t.psum(a, b));
		}
	}

	return 0;
}