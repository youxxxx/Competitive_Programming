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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* dfs(TreeNode* cur,TreeNode* cur2,TreeNode* target) {
		if (cur == target) {
			return cur2;
		}
		
		if (cur->left) {
			TreeNode *rvalue = dfs(cur->left, cur2->left, target);

			if (rvalue) {
				return rvalue;
			}
		}

		if (cur->right) {
			TreeNode *rvalue = dfs(cur->right, cur2->right, target);

			if (rvalue) {
				return rvalue;
			}
		}
		
		return NULL;
	}

	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		return dfs(original, cloned, target);
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}