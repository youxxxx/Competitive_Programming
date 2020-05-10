#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> arr;
	TreeNode *sol;

	void dfs(TreeNode *cur) {
		if (cur->left) {
			dfs(cur->left);
		}

		arr.push_back(cur->val);

		if (cur->right) {
			dfs(cur->right);
		}
	}

	void build(TreeNode **cur, int lb, int ub) {
		int mid;
		mid = (lb + ub) / 2;

		*cur = new TreeNode(arr[mid]);

		if (mid > lb) {
			build(&((*cur)->left), lb, mid);
		}

		if (mid + 1 < ub) {
			build(&((*cur)->right), mid + 1, ub);
		}
	}

	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		build(&sol, 0, arr.size());

		return sol;
	}
};

int main()
{
	TreeNode *t;

	t = new TreeNode(1);
	t->right = new TreeNode(2);
	t->right->right = new TreeNode(3);
	t->right->right->right = new TreeNode(4);

	Solution s;

	s.balanceBST(t);
}