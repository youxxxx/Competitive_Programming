#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string str;
int ptr;
char operandtype[4] = { '0','1','x','X' };
char operatortype[3] = { '&', '|', '^' };
vector<pair<int, int>> sheet[4][4];

class node
{
public:
	bool operand;
	int val;
	node *left;
	node *right;
	int cnt[4];

	node(bool type = false, node *left_input = NULL, node *right_input = NULL, int val_input = -1)
	{
		int i;

		operand = type;
		left = left_input;
		right = right_input;
		val = val_input;

		if (type)
		{
			for (i = 0; i < 4; i++)
			{
				cnt[i] = 1;
			}

			cnt[val] = 0;
		}

		else
		{
			for (i = 0; i < 4; i++)
			{
				cnt[i] = -1;
			}
		}
	}

	~node()
	{
		delete left;
		delete right;
	}
};

void construct(node **cur)
{
	int i;
	int opcode;

	if (str[ptr] != '(')
	{
		for (i = 0; i < 4; i++)
		{
			if (str[ptr] == operandtype[i])
			{
				opcode = i;

				break;
			}
		}

		*cur = new node(true, 0, 0, opcode);

		ptr++;
	}

	else
	{
		*cur = new node();

		ptr++;

		construct(&((*cur)->left));

		for (i = 0; i < 3; i++)
		{
			if (str[ptr] == operatortype[i])
			{
				opcode = i;

				break;
			}
		}

		(*cur)->val = opcode;
		
		ptr++;

		construct(&((*cur)->right));

		ptr++;
	}
}

void dfs(node *cur)
{
	int i, j, k;
	int lmin, cand;
	int a, b;

	if (cur->operand)
	{
		return;
	}

	dfs(cur->left);
	dfs(cur->right);

	for (i = 0; i < 4; i++)
	{
		lmin = -1;

		for (j = 0; j < sheet[cur->val][i].size(); j++)
		{
			a = sheet[cur->val][i][j].first;
			b = sheet[cur->val][i][j].second;

			if (cur->left->cnt[a] != -1 && cur->right->cnt[b] != -1)
			{
				cand = cur->left->cnt[a] + cur->right->cnt[b];

				if (lmin == -1 || cand < lmin)
				{
					lmin = cand;
				}
			}
		}

		for (k = 0; k < 3; k++)
		{
			if (k == cur->val)
			{
				continue;
			}

			for (j = 0; j < sheet[k][i].size(); j++)
			{
				a = sheet[k][i][j].first;
				b = sheet[k][i][j].second;

				if (cur->left->cnt[a] != -1 && cur->right->cnt[b] != -1)
				{
					cand = cur->left->cnt[a] + cur->right->cnt[b] + 1;

					if (lmin == -1 || cand < lmin)
					{
						lmin = cand;
					}
				}
			}
		}

		cur->cnt[i] = lmin;
	}
}

int main()
{
	int t, z;
	int i;
	int n;
	char input[1000];
	node *root;

	sheet[0][0].push_back(make_pair(0, 0));
	sheet[0][0].push_back(make_pair(0, 1));
	sheet[0][0].push_back(make_pair(0, 2));
	sheet[0][0].push_back(make_pair(0, 3));
	sheet[0][0].push_back(make_pair(1, 0));
	sheet[0][0].push_back(make_pair(2, 0));
	sheet[0][0].push_back(make_pair(3, 0));
	sheet[0][0].push_back(make_pair(2, 3));
	sheet[0][0].push_back(make_pair(3, 2));
	sheet[0][1].push_back(make_pair(1, 1));
	sheet[0][2].push_back(make_pair(1, 2));
	sheet[0][2].push_back(make_pair(2, 1));
	sheet[0][2].push_back(make_pair(2, 2));
	sheet[0][3].push_back(make_pair(1, 3));
	sheet[0][3].push_back(make_pair(3, 1));
	sheet[0][3].push_back(make_pair(3, 3));

	sheet[1][0].push_back(make_pair(0, 0));
	sheet[1][1].push_back(make_pair(0, 1));
	sheet[1][1].push_back(make_pair(1, 0));
	sheet[1][1].push_back(make_pair(1, 1));
	sheet[1][1].push_back(make_pair(1, 2));
	sheet[1][1].push_back(make_pair(1, 3));
	sheet[1][1].push_back(make_pair(2, 1));
	sheet[1][1].push_back(make_pair(2, 3));
	sheet[1][1].push_back(make_pair(3, 1));
	sheet[1][1].push_back(make_pair(3, 2));
	sheet[1][2].push_back(make_pair(0, 2));
	sheet[1][2].push_back(make_pair(2, 0));
	sheet[1][2].push_back(make_pair(2, 2));
	sheet[1][3].push_back(make_pair(0, 3));
	sheet[1][3].push_back(make_pair(3, 0));
	sheet[1][3].push_back(make_pair(3, 3));

	sheet[2][0].push_back(make_pair(0, 0));
	sheet[2][0].push_back(make_pair(1, 1));
	sheet[2][0].push_back(make_pair(2, 2));
	sheet[2][0].push_back(make_pair(3, 3));
	sheet[2][1].push_back(make_pair(0, 1));
	sheet[2][1].push_back(make_pair(1, 0));
	sheet[2][1].push_back(make_pair(2, 3));
	sheet[2][1].push_back(make_pair(3, 2));
	sheet[2][2].push_back(make_pair(0, 2));
	sheet[2][2].push_back(make_pair(1, 3));
	sheet[2][2].push_back(make_pair(2, 0));
	sheet[2][2].push_back(make_pair(3, 1));
	sheet[2][3].push_back(make_pair(0, 3));
	sheet[2][3].push_back(make_pair(1, 2));
	sheet[2][3].push_back(make_pair(2, 1));
	sheet[2][3].push_back(make_pair(3, 0));

	freopen("mr_x.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		if (str.size() == 1)
		{
			if (str[0] == '0' || str[0] == '1')
			{
				printf("Case #%d: 0\n", z + 1);
			}

			else
			{
				printf("Case #%d: 1\n", z + 1);
			}

			continue;
		}

		ptr = 0;

		construct(&root);

		dfs(root);

		printf("Case #%d: %d\n", z + 1, root->cnt[0] < root->cnt[1] ? root->cnt[0] : root->cnt[1]);

		delete root;
	}

	return 0;
}