#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	vector<int> list;

	int rec(TreeNode *cur) {
		int add = 0;

		if (list.size() >= 2) {
			if (!(list[list.size() - 2] % 2)) {
				add = cur->val;
			}
		}

		if (cur->left) {
			list.push_back(cur->val);
			add += rec(cur->left);
			list.pop_back();
		}

		if (cur->right) {
			list.push_back(cur->val);
			add += rec(cur->right);
			list.pop_back();
		}

		return add;
	}
	int sumEvenGrandparent(TreeNode* root) {
		if (!root) {
			return 0;
		}

		return rec(root);
	}
};

int main()
{
	Solution s;

	return 0;
}