#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<deque>
#include<cstring>

#define one26 67108863

using namespace std;

class node
{
public:
	node *left;
	node *right;
	node *parent;
	int lb;
	int ub;
	int val;
	int *ref;

	int rec(int l, int r, int *tree, node *p)
	{
		ref = tree;
		int mid;

		parent = p;
		lb = l;
		ub = r;

		if (lb == ub)
		{
			val = ref[lb];

			return ref[lb];
		}

		left = new node;
		right = new node;

		mid = (l + r) / 2;

		/*
		sum += left->rec(l, mid, tree, this);
		sum += right->rec(mid + 1, r, tree, this);

		val = sum;
		*/

		val = left->rec(l, mid, tree, this) | right->rec(mid + 1, r, tree, this);

		return val;
	}

	int range(int l, int r)
	{
		int mid;

		if (l == lb&&r == ub)
		{
			//ref->bottom[lb] = this;

			return val;
		}

		mid = (lb + ub) / 2;

		if (r <= mid)
		{
			return left->range(l, r);
		}

		if (l >= mid + 1)
		{
			return right->range(l, r);
		}

		return left->range(l, mid) | right->range(mid + 1, r);
	}

	void edit(int arg,int bit)
	{
		int mask;

		if (arg == 0)
		{
			mask = one26;

			mask -= (1 << bit);

			val = val&mask;
		}

		else
		{
			mask = (1 << bit);

			val = val | mask;
		}

		if (parent != NULL)
		{
			parent->recalc();
		}
	}

	void recalc()
	{
		val = left->val | right->val;

		if (parent != NULL)
		{
			parent->recalc();
		}
	}
};

class segtree
{
public:
	int arr[100001];
	int size;
	node *head;
	node *bottom[100001];

	segtree()
	{
	}

	void rec(node *cur)
	{
		if (cur->lb == cur->ub)
		{
			bottom[cur->lb] = cur;

			return;
		}

		rec(cur->left);
		rec(cur->right);
	}

	void make()
	{
		head = new node;
		
		head->rec(0, size - 1, arr, NULL);

		rec(head);
	}

	int range(int l, int r)
	{
		return head->range(l, r);
	}

	void edit(int idx, int arg, int bit)
	{
		bottom[idx]->edit(arg, bit);
	}
};

int main()
{
	string str;
	char input[100001];
	int n, m;
	segtree t;
	int i, j;
	int op;
	int idx;
	char letter;
	int l, r;
	int sol;
	int ret;

	//freopen("input.txt", "r", stdin);

	scanf("%s", input);
	str = input;
	n = str.size();

	scanf("%d", &m);

	for (j = 0; j < n; j++)
	{
		t.arr[j] = 0;
	}

	for (i = 0; i < n; i++)
	{
		t.arr[i] = t.arr[i] | (1 << (str[i] - 'a'));
	}

	t.size = n;

	t.make();

	for (i = 0; i < m; i++)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%d %c", &idx, &letter);

			idx--;

			t.edit(idx, 0, str[idx] - 'a');

			str[idx] = letter;

			t.edit(idx, 1, str[idx] - 'a');
		}

		else
		{
			scanf("%d %d", &l, &r);

			ret = t.range(l - 1, r - 1);

			sol = 0;

			for (j = 0; j < 26; j++)
			{
				sol += ret % 2;

				ret /= 2;
			}

			printf("%d\n", sol);
		}
	}

	return 0;
}