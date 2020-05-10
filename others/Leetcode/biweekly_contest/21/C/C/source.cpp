#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lmax;

	Solution()
	{
		lmax = 0;
	}

	int rec(TreeNode *cur,int dir) {
		if (cur == NULL) {
			return 0;
		}

		int l = 0, r = 0;

		if (cur->left) {
			l = rec(cur->left, 0);
		}
		
		if (cur->right) {
			r = rec(cur->right, 1);
		}

		if (l > lmax) {
			lmax = l;
		}

		if (r > lmax) {
			lmax = r;
		}

		if (dir == 0) {
			return r + 1;
		}

		else {
			return l + 1;
		}
	}

	int longestZigZag(TreeNode* root) {
		int l, r;

		if (root->left) {
			l = rec(root->left, 0);

			if (l > lmax) {
				lmax = l;
			}
		}

		if (root->right) {
			r = rec(root->right, 1);

			if (r > lmax) {
				lmax = r;
			}
		}

		return lmax;
	}
};

int main()
{
	Solution s;
}