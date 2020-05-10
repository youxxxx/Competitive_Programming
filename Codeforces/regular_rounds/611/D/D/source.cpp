#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<set>

using namespace std;

class node
{
public:
	node *next;
	int first;
	int second;

	node(int a, int b, node *prev=NULL)
	{
		first = a;
		second = b;

		if (prev != NULL)
		{
			prev->next = this;
		}
	}
};

class llist
{
public:
	node *head;
	node *ptr;

	llist(int n)
	{
		node *temp;

		head = new node(0, 0);
		temp = new node(0, 1, head);

		for (int i = 1; i < n; i++)
		{
			node *temp2;

			temp2 = new node(i, 0, temp);
			temp = temp2;

			temp2 = new node(i, 1, temp);
			temp = temp2;
		}

		temp->next = head;

		ptr = temp;
	}

	void remove()
	{
		node *temp;

		temp = ptr->next;

		ptr->next = temp->next;

		delete temp;
	}
};

int main()
{
	long long n, m;

	scanf("%lld %lld", &n, &m);
	long long space[200001];
	long long cnt[400001] = { 0, };
	vector<long long> tree;

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		tree.push_back(input);
	}

	sort(tree.begin(), tree.end());

	for (long long i = 0; i < n - 1; i++)
	{
		space[i] = tree[i + 1] - tree[i] - 1;
	}

	/*
	vector<pair<long long, long long>> place;

	for (long long i = 0; i < n; i++)
	{
		place.push_back({ i,0 });
		place.push_back({ i,1 });
	}
	*/

	vector<long long> sol;
	long long dist = 0;
	llist *t;

	t = new llist(n);

	for (long long i = 0; i < m; i++)
	{
		while (!(t->ptr->next->first == 0 && t->ptr->next->second == 0 || t->ptr->next->first == n - 1 && t->ptr->next->second == 1) && space[t->ptr->next->first + t->ptr->next->second - 1] == 0)
		{
			t->remove();
		}

		if (!(t->ptr->next->first == 0 && t->ptr->next->second == 0 || t->ptr->next->first == n - 1 && t->ptr->next->second == 1))
		{
			space[t->ptr->next->first + t->ptr->next->second - 1]--;
		}

		long long spot;

		spot = tree[t->ptr->next->first];

		if (t->ptr->next->second == 0)
		{
			spot -= ++cnt[t->ptr->next->first * 2 + t->ptr->next->second];
		}

		else
		{
			spot += ++cnt[t->ptr->next->first * 2 + t->ptr->next->second];
		}

		dist += cnt[t->ptr->next->first * 2 + t->ptr->next->second];

		sol.push_back(spot);

		t->ptr = t->ptr->next;
	}

	printf("%lld\n", dist);

	for (long long i = 0; i < m; i++)
	{
		printf("%lld ", sol[i]);
	}

	return 0;
}