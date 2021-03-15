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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) {
			return 0;
		}

		if (root->val < low) {
			if (!root->right) {
				return 0;
			}

			return trimBST(root->right, low, high);
		}

		if (root->val > high) {
			if (!root->left) {
				return 0;
			}

			return trimBST(root->left, low, high);
		}

		if (root->left) {
			root->left = trimBST(root->left, low, high);
		}

		if (root->right) {
			root->right = trimBST(root->right, low, high);
		}

		return root;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}