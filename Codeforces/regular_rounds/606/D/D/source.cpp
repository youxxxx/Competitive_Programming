#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class node
{
public:
	node *path[2];
	int ptr;

	node()
	{
		path[0] = path[1] = NULL;

		ptr = 0;
	}
};

class tree
{
public:
	node *root;

	tree()
	{
		root = new node;
	}

	void insert(string &str, int idx)
	{
		node *cur;

		cur = root;

		for (int i = 0; i < str.size(); i++)
		{
			int next;

			next = str[i] - '0';

			if (cur->path[next] == NULL)
			{
				cur->path[next] = new node;
			}

			cur = cur->path[next];
		}

		cur->ptr = idx;
	}

	int duplicate(string &str)
	{
		node *cur;

		cur = root;

		for (int i = str.size() - 1; i >= 0; i--)
		{
			int next;

			next = str[i] - '0';

			if (cur->path[next] == NULL)
			{
				return 0;
			}

			cur = cur->path[next];
		}

		return cur->ptr;
	}
};

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		bool noreverse[200001] = { 0, };

		tree *t;

		t = new tree;

		scanf("%d", &n);

		vector<string> arr;

		arr.push_back(" ");

		for (int i = 1; i <= n; i++)
		{
			char input[4000001];
			string str;

			scanf("%s", input);
			str = input;

			int ret;

			ret = t->duplicate(str);

			if (ret)
			{
				noreverse[ret] = noreverse[i] = true;
			}

			else
			{
				t->insert(str, i);
			}

			arr.push_back(str);
		}

		vector<int> list[2][2];
		int tot[2][2] = { 0, };
		int changeable[2][2] = { 0, };

		for (int i = 1; i <= n; i++)
		{
			if (!noreverse[i])
			{
				list[arr[i].front() - '0'][arr[i].back() - '0'].push_back(i);
				changeable[arr[i].front() - '0'][arr[i].back() - '0']++;
			}

			tot[arr[i].front() - '0'][arr[i].back() - '0']++;
		}

		if (tot[0][0] && tot[1][1] && !tot[0][1] && !tot[1][0])
		{
			printf("-1\n");

			continue;
		}
		
		int diff;

		diff = tot[0][1] - tot[1][0];

		if (abs(diff) <= 1)
		{
			printf("0\n\n");

			continue;
		}

		if (diff > 0)
		{
			if (changeable[0][1] < abs(diff) / 2)
			{
				printf("-1\n");

				continue;
			}

			printf("%d\n", abs(diff) / 2);

			for (int i = 0; i < abs(diff) / 2; i++)
			{
				printf("%d ", list[0][1][i]);
			}

			printf("\n");
		}

		else
		{
			if (changeable[1][0] < abs(diff) / 2)
			{
				printf("-1\n");

				continue;
			}

			printf("%d\n", abs(diff) / 2);

			for (int i = 0; i < abs(diff) / 2; i++)
			{
				printf("%d ", list[1][0][i]);
			}

			printf("\n");
		}
	}

	return 0;
}