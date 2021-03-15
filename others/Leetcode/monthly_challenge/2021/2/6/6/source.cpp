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
	vector<int> sol;
	void dfs(TreeNode *cur,int depth) {
		if (!cur) {
			return;
		}

		if ((int)sol.size() == depth) {
			sol.push_back(cur->val);
		}

		else {
			sol[depth] = cur->val;
		}

		dfs(cur->left, depth + 1);
		dfs(cur->right, depth + 1);
	}

	vector<int> rightSideView(TreeNode* root) {
		dfs(root, 0);

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}