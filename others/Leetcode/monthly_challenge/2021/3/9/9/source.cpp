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
	void dfs(TreeNode *cur, int v, int d) {
		if (!cur) {
			return;
		}

		if (d == 1) {
			TreeNode *l = new TreeNode(v);
			TreeNode *r = new TreeNode(v);

			l->left = cur->left;
			r->right = cur->right;

			cur->left = l;
			cur->right = r;

			return;
		}

		dfs(cur->left, v, d - 1);
		dfs(cur->right, v, d - 1);
	}
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode *t = new TreeNode(v);

			t->left = root;

			return t;
		}

		dfs(root, v, d - 1);

		return root;
	}
};

int main()
{

}