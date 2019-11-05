#include<cstdio>
#include<vector>
#include<string>

using namespace std;

class node
{
	friend class tree;

public:
	node *left;
	node *right;
	int tot;
	vector<int> key;

	void rec(node *paste, node *copy)
	{

	}

	node()
	{
		tot = 1;

		//key.push_back(0);
		left = NULL;
		right = NULL;
	}

	node(const node &other)
	{
		tot = other.tot;
		
		if (other.left)
		{
			this->left = new node(*(other.left));
		}

		else
		{
			this->left = NULL;
		}

		if (other.right)
		{
			this->right = new node(*(other.right));
		}

		else
		{
			this->right = NULL;
		}

		this->key = other.key;
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

	tree(const tree &other)
	{
		root = new node(*(other.root));
	}
};

int main()
{
	int n, q;
	vector<string> arr, query;
	vector<int> lb, rb;
	char *input;
	string str;
	int i, j;
	int l, r;
	int max = 0;
	vector<tree*> t;
	tree *temp;
	node *ptr, *ptr2;

	input = new char[1000001];

	arr.push_back(str);

	scanf("%d %d", &n, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		if (str.size() > max)
		{
			max = str.size();
		}

		arr.push_back(str);
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d %d %s", &l, &r, input);

		str = input;

		if (str.size() > max)
		{
			max = str.size();
		}

		lb.push_back(l);
		rb.push_back(r);

		query.push_back(str);
	}

	temp = new tree;

	temp->root->tot--;

	t.push_back(temp);

	temp = new tree;

	ptr = temp->root;

	//ptr->tot++;

	for (j = 0; j < max - arr[1].size(); j++)
	{		
		ptr->left = new node;

		ptr = ptr->left;
	}

	for (j = 0; j < arr[1].size(); j++)
	{
		if (arr[1][j] == '0')
		{
			ptr->left = new node;

			ptr = ptr->left;
		}

		else
		{
			ptr->right = new node;

			ptr = ptr->right;
		}
	}

	ptr->key.push_back(1);

	t.push_back(temp);

	for (i = 2; i <= n; i++)
	{
		temp = new tree(*t[i - 1]);

		ptr = temp->root;

		ptr->tot++;

		for (j = 0; j < max - arr[i].size(); j++)
		{
			if (!(ptr->left))
			{
				ptr->left = new node;
			}

			else
			{
				ptr->left->tot++;
			}

			ptr = ptr->left;
		}

		for (j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == '0')
			{
				if (!(ptr->left))
				{
					ptr->left = new node;
				}

				else
				{
					ptr->left->tot++;
				}

				ptr = ptr->left;
			}

			else
			{
				if (!(ptr->right))
				{
					ptr->right = new node;
				}

				else
				{
					ptr->right->tot++;
				}

				ptr = ptr->right;
			}
		}

		ptr->key.push_back(i);

		//ptr->tot++;

		t.push_back(temp);
	}

	for (i = 0; i < q; i++)
	{
		/*
		scanf("%d %d %s", &l, &r, input);

		str = input;
		*/

		l = lb[i];
		r = rb[i];
		str = query[i];

		ptr = t[l - 1]->root;
		
		ptr2 = t[r]->root;

		for (j = 0; j < max - str.size(); j++)
		{
			if (ptr2->right && (!ptr || !ptr->right || ptr2->right->tot - ptr->right->tot > 0))
			{
				ptr2 = ptr2->right;

				if (ptr)
				{
					ptr = ptr->right;
				}
			}

			else
			{
				ptr2 = ptr2->left;

				if (ptr)
				{
					ptr = ptr->left;
				}
			}
		}

		for (j = 0; j < str.size(); j++)
		{
			if (str[j] == '0')
			{
				if (ptr2->right && (!ptr || !ptr->right || ptr2->right->tot - ptr->right->tot > 0))
				{
					ptr2 = ptr2->right;

					if (ptr)
					{
						ptr = ptr->right;
					}
				}

				else
				{
					ptr2 = ptr2->left;

					if (ptr)
					{
						ptr = ptr->left;
					}
				}
			}

			if (str[j] == '1')
			{
				if (ptr2->left && (!ptr || !ptr->left || ptr2->left->tot - ptr->left->tot > 0))
				{
					ptr2 = ptr2->left;

					if (ptr)
					{
						ptr = ptr->left;
					}
				}

				else
				{
					ptr2 = ptr2->right;

					if (ptr)
					{
						ptr = ptr->right;
					}
				}
			}
		}

		if (!ptr)
		{
			printf("%d\n", ptr2->key[0]);
		}

		else
		{
			printf("%d\n", ptr2->key[ptr->tot]);
		}
	}

	return 0;
}