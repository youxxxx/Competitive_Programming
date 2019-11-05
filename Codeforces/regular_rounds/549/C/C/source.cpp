#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>

using namespace std;
priority_queue<int, vector<int>, greater<int> > q;

struct node
{
	int parent;
	vector<int> child;
	int c;
};

vector<node> arr;

bool dfs(int cur)
{
	int i;
	int next;
	bool res;
	bool ret;

	res = (bool)arr[cur].c;

	for (i = 0; i < arr[cur].child.size(); i++)
	{
		next = arr[cur].child[i];

		ret = dfs(next);

		res = res&&ret;
	}

	if (res)
	{
		q.push(cur);
	}

	return arr[cur].c;
}

int main()
{
	int n;
	int root;
	int i;
	int input1, input2;
	node emp;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		arr.push_back(emp);
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &input1, &input2);

		arr[i].parent = input1;
		arr[i].c = input2;

		if (input1 == -1)
		{
			root = i;
		}

		else
		{
			arr[input1].child.push_back(i);
		}
	}

	if (dfs(root))
	{
		q.push(root);
	}

	if (q.empty())
	{
		printf("-1\n");
	}

	else
	{
		while (!q.empty())
		{
			printf("%d ", q.top());

			q.pop();
		}
	}

	return 0;
}