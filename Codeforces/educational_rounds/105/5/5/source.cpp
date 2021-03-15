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
	vector<double> sol;
	vector<int> cnt;

	void dfs(TreeNode *cur, int depth) {
		if (!cur) {
			return;
		}

		if ((int)sol.size() - 1 < depth) {
			sol.push_back(0.0);

			cnt.push_back(0);
		}
		
		sol[depth] += cur->val;
		cnt[depth]++;

		dfs(cur->left, depth + 1);

		dfs(cur->right, depth + 1);
	}

	vector<double> averageOfLevels(TreeNode* root) {
		dfs(root, 0);

		for (int i = 0; i < (int)sol.size(); i++) {
			sol[i] /= (double)cnt[i];
		}

		return sol;
	}
};

int main()
{

}