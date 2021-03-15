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
	map<int, vector<pair<int, int>>> list;

	void dfs(TreeNode *cur, int x, int y) {
		list[x].push_back({ y,cur->val });

		if (cur->left) {
			dfs(cur->left, x - 1, y + 1);
		}

		if (cur->right) {
			dfs(cur->right, x + 1, y + 1);
		}
	}
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> sol;

		dfs(root, 0, 0);

		for (map<int, vector<pair<int, int>>>::iterator it = list.begin(); it != list.end(); it++) {
			vector<int> emp;

			sort(it->second.begin(), it->second.end());

			for (int i = 0; i < (int)(it->second.size()); i++) {
				emp.push_back(it->second[i].second);
			}

			sol.push_back(emp);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}