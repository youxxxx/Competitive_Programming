#include<cstdio>
#include<vector>

using namespace std;

//vector<pair<pair<int, int>, long long>> chocolates;
int n, m;
vector<long long> acc;

class node
{
public:
	node* left;
	node* right;
	long long lmax;
	pair<int, int> seg;

	node(int lb, int ub)
	{
		left = NULL;
		right = NULL;
		seg.first = lb;
		seg.second = ub;
	}
};

long long dfs(node* cur,int cut)
{
	long long larger;

	if (cur->left == NULL&&cur->right == NULL)
	{
		if (cur->seg.first < cut&&cur->seg.second > cut)
		{
			cur->left = new node(cur->seg.first, cut);
			cur->left->lmax = acc[cut] - acc[cur->seg.first];			
			cur->right = new node(cut, cur->seg.second);
			cur->right->lmax = acc[cur->seg.second] - acc[cut];

			larger = cur->left->lmax;

			if (cur->right->lmax > larger)
			{
				larger = cur->right->lmax;
			}

			cur->lmax = larger;

			return larger;
		}

		return cur->lmax;
	}

	if (cur->seg.first < cut&&cur->seg.second > cut)
	{
		if (cur->left->seg.first < cut&&cur->left->seg.second > cut)
		{
			larger = dfs(cur->left, cut);

			if (cur->right->lmax > larger)
			{
				larger = cur->right->lmax;
			}
		}

		else
		{
			larger = dfs(cur->right, cut);

			if (cur->left->lmax > larger)
			{
				larger = cur->left->lmax;
			}
		}

		cur->lmax = larger;

		return larger;
	}

	return cur->lmax;
}

int main()
{
	int i, j;
	long long res;
	long long input;
	int cut;
	node *root;

	scanf("%d %d", &n, &m);

	acc.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		acc.push_back(acc[i] + input);
	}

	root = new node(0,n);

	root->lmax = acc[n];

	for (i = 0; i < m; i++)
	{
		scanf("%d", &cut);
		
		res = dfs(root, cut);

		printf("%lld\n", res);
		
		/*
		for (j = 0; j < chocolates.size(); j++)
		{
			if (chocolates[j].first.first < cut&&chocolates[j].first.second > cut)
			{
				if (acc[cut] - acc[chocolates[j].first.first] > lmax)
				{
					lmax = acc[cut] - acc[chocolates[j].first.first];
				}

				if (acc[chocolates[j].first.second] - acc[cut]  > lmax)
				{
					lmax = acc[chocolates[j].first.second] - acc[cut];
				}

				chocolates.insert(chocolates.begin() + j + 1, pair<pair<int, int>, long long>(pair<int, int>(chocolates[j].first.first, cut), acc[cut] - acc[chocolates[j].first.first]));

				chocolates.insert(chocolates.begin() + j + 1, pair<pair<int, int>, long long>(pair<int, int>(cut, chocolates[j].first.second), acc[chocolates[j].first.second] - acc[cut]));

				chocolates.erase(chocolates.begin() + j);

				j++;
			}

			else
			{
				if (chocolates[j].second > lmax)
				{
					lmax = chocolates[j].second;
				}
			}
		}

		printf("%lld\n", lmax);
		*/
	}

	return 0;
}