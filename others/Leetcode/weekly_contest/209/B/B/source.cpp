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

class Solution {
public:
	vector<int> arr[100001];
	int lmax;

	void dfs(TreeNode *cur, int depth) {
		if (depth > lmax) {
			lmax = depth;
		}

		if (cur->left) {
			dfs(cur->left, depth + 1);
		}

		if (cur->right) {
			dfs(cur->right, depth + 1);
		}

		arr[depth].push_back(cur->val);
	}

	bool isEvenOddTree(TreeNode* root) {
		lmax = 0;

		if (!root) {
			return true;
		}

		dfs(root, 0);

		for (int i = 0; i <= lmax; i++) {
			if (!(i % 2)) {
				for (int j = 0; j < (int)arr[i].size(); j++) {
					if (!(arr[i][j] % 2)) {
						return false;
					}
				}

				for (int j = 0; j < (int)arr[i].size() - 1; j++) {
					if (arr[i][j] >= arr[i][j + 1]) {
						return false;
					}
				}
			}

			else {
				for (int j = 0; j < (int)arr[i].size(); j++) {
					if (arr[i][j] % 2) {
						return false;
					}
				}

				for (int j = 0; j < (int)arr[i].size() - 1; j++) {
					if (arr[i][j] <= arr[i][j + 1]) {
						return false;
					}
				}
			}
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}