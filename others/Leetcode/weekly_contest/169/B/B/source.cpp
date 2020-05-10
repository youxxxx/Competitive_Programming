#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> rvalue;

	void dfs(TreeNode *node)
	{
		if (node == NULL) {
			return;
		}

		rvalue.push_back(node->val);

		dfs(node->left);
		dfs(node->right);
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		dfs(root1);
		dfs(root2);

		sort(rvalue.begin(), rvalue.end());

		return rvalue;
	}
};

int main()
{
	Solution s;

	return 0;
}