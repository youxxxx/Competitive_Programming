#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
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
	int sum;

	void dfs(TreeNode *cur) {
		if (cur->right) {
			dfs(cur->right);
		}

		sum += cur->val;

		cur->val = sum;

		if (cur->left) {
			dfs(cur->left);
		}
	}

	TreeNode* convertBST(TreeNode* root) {
		if (!root) {
			return 0;
		}

		sum = 0;

		dfs(root);

		return root;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}