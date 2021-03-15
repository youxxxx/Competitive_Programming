#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> cnt;

	int dfs(TreeNode *cur)
	{
		int rvalue = 0;

		cnt[cur->val]++;

		if (!(cur->left) && !(cur->right))
		{
			int tot = 0;

			for (int i = 0; i < 10; i++)
			{
				tot += cnt[i] % 2;
			}

			if (tot < 2)
			{
				rvalue = 1;
			}
		}

		else
		{
			if (cur->left)
			{
				rvalue += dfs(cur->left);
			}

			if (cur->right)
			{
				rvalue += dfs(cur->right);
			}
		}

		cnt[cur->val]--;

		return rvalue;
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		for (int i = 0; i < 10; i++)
		{
			cnt.push_back(0);
		}

		return dfs(root);
	}
};

using namespace std;

int main()
{

	return 0;
}